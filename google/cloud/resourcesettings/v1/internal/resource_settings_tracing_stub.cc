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
// source: google/cloud/resourcesettings/v1/resource_settings.proto

#include "google/cloud/resourcesettings/v1/internal/resource_settings_tracing_stub.h"
#include "google/cloud/internal/grpc_opentelemetry.h"

namespace google {
namespace cloud {
namespace resourcesettings_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

ResourceSettingsServiceTracingStub::ResourceSettingsServiceTracingStub(
    std::shared_ptr<ResourceSettingsServiceStub> child)
    : child_(std::move(child)) {}

StatusOr<google::cloud::resourcesettings::v1::ListSettingsResponse>
ResourceSettingsServiceTracingStub::ListSettings(
    grpc::ClientContext& context,
    google::cloud::resourcesettings::v1::ListSettingsRequest const& request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.resourcesettings.v1.ResourceSettingsService",
      "ListSettings");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->ListSettings(context, request));
}

StatusOr<google::cloud::resourcesettings::v1::Setting>
ResourceSettingsServiceTracingStub::GetSetting(
    grpc::ClientContext& context,
    google::cloud::resourcesettings::v1::GetSettingRequest const& request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.resourcesettings.v1.ResourceSettingsService", "GetSetting");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->GetSetting(context, request));
}

StatusOr<google::cloud::resourcesettings::v1::Setting>
ResourceSettingsServiceTracingStub::UpdateSetting(
    grpc::ClientContext& context,
    google::cloud::resourcesettings::v1::UpdateSettingRequest const& request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.resourcesettings.v1.ResourceSettingsService",
      "UpdateSetting");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->UpdateSetting(context, request));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<ResourceSettingsServiceStub>
MakeResourceSettingsServiceTracingStub(
    std::shared_ptr<ResourceSettingsServiceStub> stub) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return std::make_shared<ResourceSettingsServiceTracingStub>(std::move(stub));
#else
  return stub;
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace resourcesettings_v1_internal
}  // namespace cloud
}  // namespace google
