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
// google/cloud/compute/region_target_http_proxies/v1/region_target_http_proxies.proto

#include "google/cloud/compute/region_target_http_proxies/v1/internal/region_target_http_proxies_option_defaults.h"
#include "google/cloud/compute/region_target_http_proxies/v1/region_target_http_proxies_connection.h"
#include "google/cloud/compute/region_target_http_proxies/v1/region_target_http_proxies_options.h"
#include "google/cloud/internal/populate_common_options.h"
#include "google/cloud/internal/populate_grpc_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace compute_region_target_http_proxies_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options RegionTargetHttpProxiesDefaultOptions(Options options) {
  options = google::cloud::internal::PopulateCommonOptions(
      std::move(options),
      "GOOGLE_CLOUD_CPP_REGION_TARGET_HTTP_PROXIES_ENDPOINT", "",
      "GOOGLE_CLOUD_CPP_REGION_TARGET_HTTP_PROXIES_AUTHORITY",
      "compute.googleapis.com");
  options =
      google::cloud::internal::PopulateGrpcOptions(std::move(options), "");
  if (!options.has<compute_region_target_http_proxies_v1::
                       RegionTargetHttpProxiesRetryPolicyOption>()) {
    options.set<compute_region_target_http_proxies_v1::
                    RegionTargetHttpProxiesRetryPolicyOption>(
        compute_region_target_http_proxies_v1::
            RegionTargetHttpProxiesLimitedTimeRetryPolicy(
                std::chrono::minutes(30))
                .clone());
  }
  if (!options.has<compute_region_target_http_proxies_v1::
                       RegionTargetHttpProxiesBackoffPolicyOption>()) {
    options.set<compute_region_target_http_proxies_v1::
                    RegionTargetHttpProxiesBackoffPolicyOption>(
        ExponentialBackoffPolicy(
            std::chrono::seconds(0), std::chrono::seconds(1),
            std::chrono::minutes(5), kBackoffScaling, kBackoffScaling)
            .clone());
  }
  if (!options.has<compute_region_target_http_proxies_v1::
                       RegionTargetHttpProxiesPollingPolicyOption>()) {
    options.set<compute_region_target_http_proxies_v1::
                    RegionTargetHttpProxiesPollingPolicyOption>(
        GenericPollingPolicy<
            compute_region_target_http_proxies_v1::
                RegionTargetHttpProxiesRetryPolicyOption::Type,
            compute_region_target_http_proxies_v1::
                RegionTargetHttpProxiesBackoffPolicyOption::Type>(
            options
                .get<compute_region_target_http_proxies_v1::
                         RegionTargetHttpProxiesRetryPolicyOption>()
                ->clone(),
            ExponentialBackoffPolicy(std::chrono::seconds(1),
                                     std::chrono::minutes(5), kBackoffScaling)
                .clone())
            .clone());
  }
  if (!options.has<
          compute_region_target_http_proxies_v1::
              RegionTargetHttpProxiesConnectionIdempotencyPolicyOption>()) {
    options.set<compute_region_target_http_proxies_v1::
                    RegionTargetHttpProxiesConnectionIdempotencyPolicyOption>(
        compute_region_target_http_proxies_v1::
            MakeDefaultRegionTargetHttpProxiesConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace compute_region_target_http_proxies_v1_internal
}  // namespace cloud
}  // namespace google
