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
// source: google/cloud/aiplatform/v1/dataset_service.proto

#include "google/cloud/aiplatform/v1/internal/dataset_option_defaults.h"
#include "google/cloud/aiplatform/v1/dataset_connection.h"
#include "google/cloud/aiplatform/v1/dataset_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/populate_common_options.h"
#include "google/cloud/internal/populate_grpc_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace aiplatform_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options DatasetServiceDefaultOptions(std::string const& location,
                                     Options options) {
  options = google::cloud::internal::PopulateCommonOptions(
      std::move(options), "GOOGLE_CLOUD_CPP_DATASET_SERVICE_ENDPOINT", "",
      "GOOGLE_CLOUD_CPP_DATASET_SERVICE_AUTHORITY",
      absl::StrCat(location, "-", "aiplatform.googleapis.com"));
  options =
      google::cloud::internal::PopulateGrpcOptions(std::move(options), "");
  if (!options.has<aiplatform_v1::DatasetServiceRetryPolicyOption>()) {
    options.set<aiplatform_v1::DatasetServiceRetryPolicyOption>(
        aiplatform_v1::DatasetServiceLimitedTimeRetryPolicy(
            std::chrono::minutes(30))
            .clone());
  }
  if (!options.has<aiplatform_v1::DatasetServiceBackoffPolicyOption>()) {
    options.set<aiplatform_v1::DatasetServiceBackoffPolicyOption>(
        ExponentialBackoffPolicy(
            std::chrono::seconds(0), std::chrono::seconds(1),
            std::chrono::minutes(5), kBackoffScaling, kBackoffScaling)
            .clone());
  }
  if (!options.has<aiplatform_v1::DatasetServicePollingPolicyOption>()) {
    options.set<aiplatform_v1::DatasetServicePollingPolicyOption>(
        GenericPollingPolicy<
            aiplatform_v1::DatasetServiceRetryPolicyOption::Type,
            aiplatform_v1::DatasetServiceBackoffPolicyOption::Type>(
            options.get<aiplatform_v1::DatasetServiceRetryPolicyOption>()
                ->clone(),
            ExponentialBackoffPolicy(std::chrono::seconds(1),
                                     std::chrono::minutes(5), kBackoffScaling)
                .clone())
            .clone());
  }
  if (!options.has<
          aiplatform_v1::DatasetServiceConnectionIdempotencyPolicyOption>()) {
    options.set<aiplatform_v1::DatasetServiceConnectionIdempotencyPolicyOption>(
        aiplatform_v1::MakeDefaultDatasetServiceConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace aiplatform_v1_internal
}  // namespace cloud
}  // namespace google
