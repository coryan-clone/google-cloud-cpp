// Copyright 2022 Google LLC
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
// source: google/cloud/bigquery/storage/v1/storage.proto

#include "google/cloud/bigquery/storage/v1/internal/bigquery_write_logging_decorator.h"
#include "google/cloud/internal/async_read_write_stream_logging.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/bigquery/storage/v1/storage.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_storage_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

BigQueryWriteLogging::BigQueryWriteLogging(
    std::shared_ptr<BigQueryWriteStub> child, TracingOptions tracing_options,
    std::set<std::string> const& components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      stream_logging_(components.find("rpc-streams") != components.end()) {}

StatusOr<google::cloud::bigquery::storage::v1::WriteStream>
BigQueryWriteLogging::CreateWriteStream(
    grpc::ClientContext& context,
    google::cloud::bigquery::storage::v1::CreateWriteStreamRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::bigquery::storage::v1::CreateWriteStreamRequest const&
              request) { return child_->CreateWriteStream(context, request); },
      context, request, __func__, tracing_options_);
}

std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
    google::cloud::bigquery::storage::v1::AppendRowsRequest,
    google::cloud::bigquery::storage::v1::AppendRowsResponse>>
BigQueryWriteLogging::AsyncAppendRows(
    google::cloud::CompletionQueue const& cq,
    std::shared_ptr<grpc::ClientContext> context) {
  using LoggingStream =
      ::google::cloud::internal::AsyncStreamingReadWriteRpcLogging<
          google::cloud::bigquery::storage::v1::AppendRowsRequest,
          google::cloud::bigquery::storage::v1::AppendRowsResponse>;

  auto request_id = google::cloud::internal::RequestIdForLogging();
  GCP_LOG(DEBUG) << __func__ << "(" << request_id << ")";
  auto stream = child_->AsyncAppendRows(cq, std::move(context));
  if (stream_logging_) {
    stream = std::make_unique<LoggingStream>(
        std::move(stream), tracing_options_, std::move(request_id));
  }
  return stream;
}

StatusOr<google::cloud::bigquery::storage::v1::WriteStream>
BigQueryWriteLogging::GetWriteStream(
    grpc::ClientContext& context,
    google::cloud::bigquery::storage::v1::GetWriteStreamRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::storage::v1::GetWriteStreamRequest const&
                 request) { return child_->GetWriteStream(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::storage::v1::FinalizeWriteStreamResponse>
BigQueryWriteLogging::FinalizeWriteStream(
    grpc::ClientContext& context,
    google::cloud::bigquery::storage::v1::FinalizeWriteStreamRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::storage::v1::
                 FinalizeWriteStreamRequest const& request) {
        return child_->FinalizeWriteStream(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::storage::v1::BatchCommitWriteStreamsResponse>
BigQueryWriteLogging::BatchCommitWriteStreams(
    grpc::ClientContext& context,
    google::cloud::bigquery::storage::v1::BatchCommitWriteStreamsRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::storage::v1::
                 BatchCommitWriteStreamsRequest const& request) {
        return child_->BatchCommitWriteStreams(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::storage::v1::FlushRowsResponse>
BigQueryWriteLogging::FlushRows(
    grpc::ClientContext& context,
    google::cloud::bigquery::storage::v1::FlushRowsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::storage::v1::FlushRowsRequest const&
                 request) { return child_->FlushRows(context, request); },
      context, request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_storage_v1_internal
}  // namespace cloud
}  // namespace google
