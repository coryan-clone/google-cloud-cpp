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
// source: google/cloud/compute/accelerator_types/v1/accelerator_types.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_COMPUTE_ACCELERATOR_TYPES_V1_INTERNAL_ACCELERATOR_TYPES_REST_METADATA_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_COMPUTE_ACCELERATOR_TYPES_V1_INTERNAL_ACCELERATOR_TYPES_REST_METADATA_DECORATOR_H

#include "google/cloud/compute/accelerator_types/v1/internal/accelerator_types_rest_stub.h"
#include "google/cloud/future.h"
#include "google/cloud/rest_options.h"
#include "google/cloud/version.h"
#include <google/cloud/compute/accelerator_types/v1/accelerator_types.pb.h>
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace compute_accelerator_types_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class AcceleratorTypesRestMetadata : public AcceleratorTypesRestStub {
 public:
  ~AcceleratorTypesRestMetadata() override = default;
  explicit AcceleratorTypesRestMetadata(
      std::shared_ptr<AcceleratorTypesRestStub> child);

  StatusOr<google::cloud::cpp::compute::v1::AcceleratorTypeAggregatedList>
  AggregatedListAcceleratorTypes(
      google::cloud::rest_internal::RestContext& rest_context,
      google::cloud::cpp::compute::accelerator_types::v1::
          AggregatedListAcceleratorTypesRequest const& request) override;

  StatusOr<google::cloud::cpp::compute::v1::AcceleratorType>
  GetAcceleratorTypes(google::cloud::rest_internal::RestContext& rest_context,
                      google::cloud::cpp::compute::accelerator_types::v1::
                          GetAcceleratorTypesRequest const& request) override;

  StatusOr<google::cloud::cpp::compute::v1::AcceleratorTypeList>
  ListAcceleratorTypes(google::cloud::rest_internal::RestContext& rest_context,
                       google::cloud::cpp::compute::accelerator_types::v1::
                           ListAcceleratorTypesRequest const& request) override;

 private:
  void SetMetadata(rest_internal::RestContext& rest_context,
                   std::vector<std::string> const& params = {});

  std::shared_ptr<AcceleratorTypesRestStub> child_;
  std::string api_client_header_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace compute_accelerator_types_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_COMPUTE_ACCELERATOR_TYPES_V1_INTERNAL_ACCELERATOR_TYPES_REST_METADATA_DECORATOR_H
