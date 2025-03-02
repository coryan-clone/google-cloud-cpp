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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_COMPUTE_ACCELERATOR_TYPES_V1_ACCELERATOR_TYPES_CONNECTION_IDEMPOTENCY_POLICY_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_COMPUTE_ACCELERATOR_TYPES_V1_ACCELERATOR_TYPES_CONNECTION_IDEMPOTENCY_POLICY_H

#include "google/cloud/idempotency.h"
#include "google/cloud/version.h"
#include <google/cloud/compute/accelerator_types/v1/accelerator_types.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace compute_accelerator_types_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class AcceleratorTypesConnectionIdempotencyPolicy {
 public:
  virtual ~AcceleratorTypesConnectionIdempotencyPolicy();

  /// Create a new copy of this object.
  virtual std::unique_ptr<AcceleratorTypesConnectionIdempotencyPolicy> clone()
      const;

  virtual google::cloud::Idempotency AggregatedListAcceleratorTypes(
      google::cloud::cpp::compute::accelerator_types::v1::
          AggregatedListAcceleratorTypesRequest const& request);

  virtual google::cloud::Idempotency GetAcceleratorTypes(
      google::cloud::cpp::compute::accelerator_types::v1::
          GetAcceleratorTypesRequest const& request);

  virtual google::cloud::Idempotency ListAcceleratorTypes(
      google::cloud::cpp::compute::accelerator_types::v1::
          ListAcceleratorTypesRequest request);
};

std::unique_ptr<AcceleratorTypesConnectionIdempotencyPolicy>
MakeDefaultAcceleratorTypesConnectionIdempotencyPolicy();

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace compute_accelerator_types_v1
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_COMPUTE_ACCELERATOR_TYPES_V1_ACCELERATOR_TYPES_CONNECTION_IDEMPOTENCY_POLICY_H
