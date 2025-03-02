// Copyright 2023 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
#include "google/cloud/internal/async_streaming_read_rpc_tracing.h"
#include "google/cloud/internal/make_status.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/testing_util/opentelemetry_matchers.h"
#include "google/cloud/testing_util/status_matchers.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace internal {
namespace {

using ::google::cloud::testing_util::EventNamed;
using ::google::cloud::testing_util::OTelAttribute;
using ::google::cloud::testing_util::SpanEventAttributesAre;
using ::google::cloud::testing_util::SpanHasAttributes;
using ::google::cloud::testing_util::SpanNamed;
using ::google::cloud::testing_util::SpanWithStatus;
using ::google::cloud::testing_util::StatusIs;
using ::testing::_;
using ::testing::AllOf;
using ::testing::ElementsAre;
using ::testing::IsEmpty;
using ::testing::Optional;
using ::testing::Pair;
using ::testing::Return;

template <typename Response>
class MockAsyncStreamingReadRpc : public AsyncStreamingReadRpc<Response> {
 public:
  ~MockAsyncStreamingReadRpc() override = default;

  MOCK_METHOD(void, Cancel, (), (override));
  MOCK_METHOD(future<bool>, Start, (), (override));
  MOCK_METHOD(future<absl::optional<Response>>, Read, (), (override));
  MOCK_METHOD(future<Status>, Finish, (), (override));
  MOCK_METHOD(StreamingRpcMetadata, GetRequestMetadata, (), (const, override));
};

using MockStream = MockAsyncStreamingReadRpc<int>;
using TestedStream = AsyncStreamingReadRpcTracing<int>;

TEST(AsyncStreamingReadRpcTracing, Cancel) {
  auto span_catcher = testing_util::InstallSpanCatcher();

  auto span = MakeSpan("span");
  auto mock = std::make_unique<MockStream>();
  EXPECT_CALL(*mock, Cancel).WillOnce([span] {
    // Verify that our "cancel" event is added before calling `TryCancel()` on
    // the underlying stream.
    span->AddEvent("test-only: underlying stream cancel");
  });
  EXPECT_CALL(*mock, Finish)
      .WillOnce(
          Return(make_ready_future(internal::CancelledError("cancelled"))));

  TestedStream stream(std::make_shared<grpc::ClientContext>(), std::move(mock),
                      span);
  stream.Cancel();
  (void)stream.Finish().get();

  auto spans = span_catcher->GetSpans();
  EXPECT_THAT(
      spans,
      ElementsAre(AllOf(
          SpanNamed("span"),
          SpanEventsAre(EventNamed("cancel"),
                        EventNamed("test-only: underlying stream cancel")))));
}

TEST(AsyncStreamingReadRpcTracing, Start) {
  auto span_catcher = testing_util::InstallSpanCatcher();

  auto span = MakeSpan("span");
  auto mock = std::make_unique<MockStream>();
  EXPECT_CALL(*mock, Start).WillOnce([] { return make_ready_future(true); });
  EXPECT_CALL(*mock, Finish)
      .WillOnce(Return(make_ready_future(internal::AbortedError("fail"))));

  TestedStream stream(std::make_shared<grpc::ClientContext>(), std::move(mock),
                      span);
  EXPECT_TRUE(stream.Start().get());
  (void)stream.Finish().get();

  auto spans = span_catcher->GetSpans();
  EXPECT_THAT(spans, ElementsAre(AllOf(SpanNamed("span"),
                                       SpanHasAttributes(OTelAttribute<bool>(
                                           "gcloud.stream_started", true)))));
}

TEST(AsyncStreamingReadRpcTracing, Read) {
  auto span_catcher = testing_util::InstallSpanCatcher();

  auto span = MakeSpan("span");
  auto mock = std::make_unique<MockStream>();
  EXPECT_CALL(*mock, Read)
      .WillOnce([] { return make_ready_future(absl::make_optional(100)); })
      .WillOnce([] { return make_ready_future(absl::make_optional(200)); })
      .WillOnce([] { return make_ready_future(absl::make_optional(300)); })
      .WillOnce(
          [] { return make_ready_future<absl::optional<int>>(absl::nullopt); });
  EXPECT_CALL(*mock, Finish)
      .WillOnce(Return(make_ready_future(internal::AbortedError("fail"))));

  TestedStream stream(std::make_shared<grpc::ClientContext>(), std::move(mock),
                      span);
  EXPECT_THAT(stream.Read().get(), Optional(100));
  EXPECT_THAT(stream.Read().get(), Optional(200));
  EXPECT_THAT(stream.Read().get(), Optional(300));
  EXPECT_FALSE(stream.Read().get().has_value());
  (void)stream.Finish().get();

  auto spans = span_catcher->GetSpans();
  EXPECT_THAT(
      spans,
      ElementsAre(AllOf(
          SpanNamed("span"),
          SpanEventsAre(
              AllOf(EventNamed("message"),
                    SpanEventAttributesAre(
                        OTelAttribute<std::string>("message.type", "RECEIVED"),
                        OTelAttribute<int>("message.id", 1))),
              AllOf(EventNamed("message"),
                    SpanEventAttributesAre(
                        OTelAttribute<std::string>("message.type", "RECEIVED"),
                        OTelAttribute<int>("message.id", 2))),
              AllOf(EventNamed("message"),
                    SpanEventAttributesAre(
                        OTelAttribute<std::string>("message.type", "RECEIVED"),
                        OTelAttribute<int>("message.id", 3)))))));
}

TEST(AsyncStreamingReadRpcTracing, Finish) {
  auto span_catcher = testing_util::InstallSpanCatcher();

  auto span = MakeSpan("span");
  auto mock = std::make_unique<MockStream>();
  EXPECT_CALL(*mock, Finish)
      .WillOnce(Return(make_ready_future(internal::AbortedError("fail"))));

  TestedStream stream(std::make_shared<grpc::ClientContext>(), std::move(mock),
                      span);
  EXPECT_THAT(stream.Finish().get(), StatusIs(StatusCode::kAborted, "fail"));

  auto spans = span_catcher->GetSpans();
  EXPECT_THAT(
      spans,
      ElementsAre(AllOf(
          SpanNamed("span"),
          SpanHasAttributes(OTelAttribute<std::string>("grpc.peer", _)),
          SpanWithStatus(opentelemetry::trace::StatusCode::kError, "fail"))));
}

TEST(AsyncStreamingReadRpcTracing, GetRequestMetadata) {
  auto mock = std::make_unique<MockStream>();
  EXPECT_CALL(*mock, GetRequestMetadata)
      .WillOnce(Return(StreamingRpcMetadata{{"key", "value"}}));

  auto span = MakeSpan("span");
  TestedStream stream(std::make_shared<grpc::ClientContext>(), std::move(mock),
                      span);
  auto md = stream.GetRequestMetadata();
  EXPECT_THAT(md, ElementsAre(Pair("key", "value")));
}

TEST(AsyncStreamingReadRpcTracing, SpanEndsOnDestruction) {
  auto span_catcher = testing_util::InstallSpanCatcher();

  {
    auto mock = std::make_unique<MockStream>();
    auto span = MakeSpan("span");
    TestedStream stream(std::make_shared<grpc::ClientContext>(),
                        std::move(mock), span);

    auto spans = span_catcher->GetSpans();
    EXPECT_THAT(spans, IsEmpty());
  }

  auto spans = span_catcher->GetSpans();
  EXPECT_THAT(spans, ElementsAre(SpanNamed("span")));
}

}  // namespace
}  // namespace internal
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace cloud
}  // namespace google
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
