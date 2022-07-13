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
// source: google/cloud/run/v2/service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RUN_SERVICES_CONNECTION_IDEMPOTENCY_POLICY_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RUN_SERVICES_CONNECTION_IDEMPOTENCY_POLICY_H

#include "google/cloud/idempotency.h"
#include "google/cloud/internal/retry_policy.h"
#include "google/cloud/version.h"
#include <google/cloud/run/v2/service.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace run {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class ServicesConnectionIdempotencyPolicy {
 public:
  virtual ~ServicesConnectionIdempotencyPolicy() = 0;

  /// Create a new copy of this object.
  virtual std::unique_ptr<ServicesConnectionIdempotencyPolicy> clone()
      const = 0;

  virtual google::cloud::Idempotency CreateService(
      google::cloud::run::v2::CreateServiceRequest const& request) = 0;

  virtual google::cloud::Idempotency GetService(
      google::cloud::run::v2::GetServiceRequest const& request) = 0;

  virtual google::cloud::Idempotency ListServices(
      google::cloud::run::v2::ListServicesRequest request) = 0;

  virtual google::cloud::Idempotency UpdateService(
      google::cloud::run::v2::UpdateServiceRequest const& request) = 0;

  virtual google::cloud::Idempotency DeleteService(
      google::cloud::run::v2::DeleteServiceRequest const& request) = 0;

  virtual google::cloud::Idempotency GetIamPolicy(
      google::iam::v1::GetIamPolicyRequest const& request) = 0;

  virtual google::cloud::Idempotency SetIamPolicy(
      google::iam::v1::SetIamPolicyRequest const& request) = 0;

  virtual google::cloud::Idempotency TestIamPermissions(
      google::iam::v1::TestIamPermissionsRequest const& request) = 0;
};

std::unique_ptr<ServicesConnectionIdempotencyPolicy>
MakeDefaultServicesConnectionIdempotencyPolicy();

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace run
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RUN_SERVICES_CONNECTION_IDEMPOTENCY_POLICY_H
