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
// source: google/cloud/beyondcorp/appgateways/v1/app_gateways_service.proto

#include "google/cloud/beyondcorp/appgateways/v1/internal/app_gateways_tracing_connection.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/internal/traced_stream_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace beyondcorp_appgateways_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

AppGatewaysServiceTracingConnection::AppGatewaysServiceTracingConnection(
    std::shared_ptr<beyondcorp_appgateways_v1::AppGatewaysServiceConnection>
        child)
    : child_(std::move(child)) {}

StreamRange<google::cloud::beyondcorp::appgateways::v1::AppGateway>
AppGatewaysServiceTracingConnection::ListAppGateways(
    google::cloud::beyondcorp::appgateways::v1::ListAppGatewaysRequest
        request) {
  auto span = internal::MakeSpan(
      "beyondcorp_appgateways_v1::AppGatewaysServiceConnection::"
      "ListAppGateways");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListAppGateways(std::move(request));
  return internal::MakeTracedStreamRange<
      google::cloud::beyondcorp::appgateways::v1::AppGateway>(std::move(span),
                                                              std::move(sr));
}

StatusOr<google::cloud::beyondcorp::appgateways::v1::AppGateway>
AppGatewaysServiceTracingConnection::GetAppGateway(
    google::cloud::beyondcorp::appgateways::v1::GetAppGatewayRequest const&
        request) {
  auto span = internal::MakeSpan(
      "beyondcorp_appgateways_v1::AppGatewaysServiceConnection::GetAppGateway");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetAppGateway(request));
}

future<StatusOr<google::cloud::beyondcorp::appgateways::v1::AppGateway>>
AppGatewaysServiceTracingConnection::CreateAppGateway(
    google::cloud::beyondcorp::appgateways::v1::CreateAppGatewayRequest const&
        request) {
  auto span = internal::MakeSpan(
      "beyondcorp_appgateways_v1::AppGatewaysServiceConnection::"
      "CreateAppGateway");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(std::move(span), child_->CreateAppGateway(request));
}

future<StatusOr<
    google::cloud::beyondcorp::appgateways::v1::AppGatewayOperationMetadata>>
AppGatewaysServiceTracingConnection::DeleteAppGateway(
    google::cloud::beyondcorp::appgateways::v1::DeleteAppGatewayRequest const&
        request) {
  auto span = internal::MakeSpan(
      "beyondcorp_appgateways_v1::AppGatewaysServiceConnection::"
      "DeleteAppGateway");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(std::move(span), child_->DeleteAppGateway(request));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<beyondcorp_appgateways_v1::AppGatewaysServiceConnection>
MakeAppGatewaysServiceTracingConnection(
    std::shared_ptr<beyondcorp_appgateways_v1::AppGatewaysServiceConnection>
        conn) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  if (internal::TracingEnabled(conn->options())) {
    conn =
        std::make_shared<AppGatewaysServiceTracingConnection>(std::move(conn));
  }
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return conn;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace beyondcorp_appgateways_v1_internal
}  // namespace cloud
}  // namespace google
