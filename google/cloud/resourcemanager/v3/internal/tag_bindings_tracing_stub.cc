// Copyright 2023 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/cloud/resourcemanager/v3/tag_bindings.proto

#include "google/cloud/resourcemanager/v3/internal/tag_bindings_tracing_stub.h"
#include "google/cloud/internal/grpc_opentelemetry.h"

namespace google {
namespace cloud {
namespace resourcemanager_v3_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

TagBindingsTracingStub::TagBindingsTracingStub(
    std::shared_ptr<TagBindingsStub> child)
    : child_(std::move(child)) {}

StatusOr<google::cloud::resourcemanager::v3::ListTagBindingsResponse>
TagBindingsTracingStub::ListTagBindings(
    grpc::ClientContext& context,
    google::cloud::resourcemanager::v3::ListTagBindingsRequest const& request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.resourcemanager.v3.TagBindings", "ListTagBindings");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->ListTagBindings(context, request));
}

future<StatusOr<google::longrunning::Operation>>
TagBindingsTracingStub::AsyncCreateTagBinding(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::resourcemanager::v3::CreateTagBindingRequest const&
        request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.resourcemanager.v3.TagBindings", "CreateTagBinding");
  {
    auto scope = opentelemetry::trace::Scope(span);
    internal::InjectTraceContext(*context, internal::CurrentOptions());
  }
  auto f = child_->AsyncCreateTagBinding(cq, context, request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

future<StatusOr<google::longrunning::Operation>>
TagBindingsTracingStub::AsyncDeleteTagBinding(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::resourcemanager::v3::DeleteTagBindingRequest const&
        request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.resourcemanager.v3.TagBindings", "DeleteTagBinding");
  {
    auto scope = opentelemetry::trace::Scope(span);
    internal::InjectTraceContext(*context, internal::CurrentOptions());
  }
  auto f = child_->AsyncDeleteTagBinding(cq, context, request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

StatusOr<google::cloud::resourcemanager::v3::ListEffectiveTagsResponse>
TagBindingsTracingStub::ListEffectiveTags(
    grpc::ClientContext& context,
    google::cloud::resourcemanager::v3::ListEffectiveTagsRequest const&
        request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.resourcemanager.v3.TagBindings", "ListEffectiveTags");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->ListEffectiveTags(context, request));
}

future<StatusOr<google::longrunning::Operation>>
TagBindingsTracingStub::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  auto span =
      internal::MakeSpanGrpc("google.longrunning.Operations", "GetOperation");
  {
    auto scope = opentelemetry::trace::Scope(span);
    internal::InjectTraceContext(*context, internal::CurrentOptions());
  }
  auto f = child_->AsyncGetOperation(cq, context, request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

future<Status> TagBindingsTracingStub::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.longrunning.Operations",
                                     "CancelOperation");
  {
    auto scope = opentelemetry::trace::Scope(span);
    internal::InjectTraceContext(*context, internal::CurrentOptions());
  }
  auto f = child_->AsyncCancelOperation(cq, context, request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<TagBindingsStub> MakeTagBindingsTracingStub(
    std::shared_ptr<TagBindingsStub> stub) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return std::make_shared<TagBindingsTracingStub>(std::move(stub));
#else
  return stub;
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace resourcemanager_v3_internal
}  // namespace cloud
}  // namespace google
