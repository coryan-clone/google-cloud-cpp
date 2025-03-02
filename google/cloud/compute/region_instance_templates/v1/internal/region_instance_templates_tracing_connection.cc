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
// source:
// google/cloud/compute/region_instance_templates/v1/region_instance_templates.proto

#include "google/cloud/compute/region_instance_templates/v1/internal/region_instance_templates_tracing_connection.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/internal/traced_stream_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace compute_region_instance_templates_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

RegionInstanceTemplatesTracingConnection::
    RegionInstanceTemplatesTracingConnection(
        std::shared_ptr<compute_region_instance_templates_v1::
                            RegionInstanceTemplatesConnection>
            child)
    : child_(std::move(child)) {}

future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
RegionInstanceTemplatesTracingConnection::DeleteRegionInstanceTemplates(
    google::cloud::cpp::compute::region_instance_templates::v1::
        DeleteRegionInstanceTemplatesRequest const& request) {
  auto span = internal::MakeSpan(
      "compute_region_instance_templates_v1::RegionInstanceTemplatesConnection:"
      ":DeleteRegionInstanceTemplates");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(std::move(span),
                           child_->DeleteRegionInstanceTemplates(request));
}

StatusOr<google::cloud::cpp::compute::v1::InstanceTemplate>
RegionInstanceTemplatesTracingConnection::GetRegionInstanceTemplates(
    google::cloud::cpp::compute::region_instance_templates::v1::
        GetRegionInstanceTemplatesRequest const& request) {
  auto span = internal::MakeSpan(
      "compute_region_instance_templates_v1::RegionInstanceTemplatesConnection:"
      ":GetRegionInstanceTemplates");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetRegionInstanceTemplates(request));
}

future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
RegionInstanceTemplatesTracingConnection::InsertRegionInstanceTemplates(
    google::cloud::cpp::compute::region_instance_templates::v1::
        InsertRegionInstanceTemplatesRequest const& request) {
  auto span = internal::MakeSpan(
      "compute_region_instance_templates_v1::RegionInstanceTemplatesConnection:"
      ":InsertRegionInstanceTemplates");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(std::move(span),
                           child_->InsertRegionInstanceTemplates(request));
}

StreamRange<google::cloud::cpp::compute::v1::InstanceTemplate>
RegionInstanceTemplatesTracingConnection::ListRegionInstanceTemplates(
    google::cloud::cpp::compute::region_instance_templates::v1::
        ListRegionInstanceTemplatesRequest request) {
  auto span = internal::MakeSpan(
      "compute_region_instance_templates_v1::RegionInstanceTemplatesConnection:"
      ":ListRegionInstanceTemplates");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListRegionInstanceTemplates(std::move(request));
  return internal::MakeTracedStreamRange<
      google::cloud::cpp::compute::v1::InstanceTemplate>(std::move(span),
                                                         std::move(sr));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<
    compute_region_instance_templates_v1::RegionInstanceTemplatesConnection>
MakeRegionInstanceTemplatesTracingConnection(
    std::shared_ptr<
        compute_region_instance_templates_v1::RegionInstanceTemplatesConnection>
        conn) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  if (internal::TracingEnabled(conn->options())) {
    conn = std::make_shared<RegionInstanceTemplatesTracingConnection>(
        std::move(conn));
  }
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return conn;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace compute_region_instance_templates_v1_internal
}  // namespace cloud
}  // namespace google
