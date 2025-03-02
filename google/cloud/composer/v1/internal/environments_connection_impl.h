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
// source: google/cloud/orchestration/airflow/service/v1/environments.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_COMPOSER_V1_INTERNAL_ENVIRONMENTS_CONNECTION_IMPL_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_COMPOSER_V1_INTERNAL_ENVIRONMENTS_CONNECTION_IMPL_H

#include "google/cloud/composer/v1/environments_connection.h"
#include "google/cloud/composer/v1/environments_connection_idempotency_policy.h"
#include "google/cloud/composer/v1/environments_options.h"
#include "google/cloud/composer/v1/internal/environments_retry_traits.h"
#include "google/cloud/composer/v1/internal/environments_stub.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace composer_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class EnvironmentsConnectionImpl : public composer_v1::EnvironmentsConnection {
 public:
  ~EnvironmentsConnectionImpl() override = default;

  EnvironmentsConnectionImpl(
      std::unique_ptr<google::cloud::BackgroundThreads> background,
      std::shared_ptr<composer_v1_internal::EnvironmentsStub> stub,
      Options options);

  Options options() override { return options_; }

  future<
      StatusOr<google::cloud::orchestration::airflow::service::v1::Environment>>
  CreateEnvironment(google::cloud::orchestration::airflow::service::v1::
                        CreateEnvironmentRequest const& request) override;

  StatusOr<google::cloud::orchestration::airflow::service::v1::Environment>
  GetEnvironment(google::cloud::orchestration::airflow::service::v1::
                     GetEnvironmentRequest const& request) override;

  StreamRange<google::cloud::orchestration::airflow::service::v1::Environment>
  ListEnvironments(google::cloud::orchestration::airflow::service::v1::
                       ListEnvironmentsRequest request) override;

  future<
      StatusOr<google::cloud::orchestration::airflow::service::v1::Environment>>
  UpdateEnvironment(google::cloud::orchestration::airflow::service::v1::
                        UpdateEnvironmentRequest const& request) override;

  future<StatusOr<
      google::cloud::orchestration::airflow::service::v1::OperationMetadata>>
  DeleteEnvironment(google::cloud::orchestration::airflow::service::v1::
                        DeleteEnvironmentRequest const& request) override;

  StatusOr<google::cloud::orchestration::airflow::service::v1::
               ExecuteAirflowCommandResponse>
  ExecuteAirflowCommand(
      google::cloud::orchestration::airflow::service::v1::
          ExecuteAirflowCommandRequest const& request) override;

  StatusOr<google::cloud::orchestration::airflow::service::v1::
               StopAirflowCommandResponse>
  StopAirflowCommand(google::cloud::orchestration::airflow::service::v1::
                         StopAirflowCommandRequest const& request) override;

  StatusOr<google::cloud::orchestration::airflow::service::v1::
               PollAirflowCommandResponse>
  PollAirflowCommand(google::cloud::orchestration::airflow::service::v1::
                         PollAirflowCommandRequest const& request) override;

  future<StatusOr<
      google::cloud::orchestration::airflow::service::v1::SaveSnapshotResponse>>
  SaveSnapshot(google::cloud::orchestration::airflow::service::v1::
                   SaveSnapshotRequest const& request) override;

  future<StatusOr<
      google::cloud::orchestration::airflow::service::v1::LoadSnapshotResponse>>
  LoadSnapshot(google::cloud::orchestration::airflow::service::v1::
                   LoadSnapshotRequest const& request) override;

  future<StatusOr<google::cloud::orchestration::airflow::service::v1::
                      DatabaseFailoverResponse>>
  DatabaseFailover(google::cloud::orchestration::airflow::service::v1::
                       DatabaseFailoverRequest const& request) override;

  StatusOr<google::cloud::orchestration::airflow::service::v1::
               FetchDatabasePropertiesResponse>
  FetchDatabaseProperties(
      google::cloud::orchestration::airflow::service::v1::
          FetchDatabasePropertiesRequest const& request) override;

 private:
  std::unique_ptr<composer_v1::EnvironmentsRetryPolicy> retry_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<composer_v1::EnvironmentsRetryPolicyOption>()) {
      return options.get<composer_v1::EnvironmentsRetryPolicyOption>()->clone();
    }
    return options_.get<composer_v1::EnvironmentsRetryPolicyOption>()->clone();
  }

  std::unique_ptr<BackoffPolicy> backoff_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<composer_v1::EnvironmentsBackoffPolicyOption>()) {
      return options.get<composer_v1::EnvironmentsBackoffPolicyOption>()
          ->clone();
    }
    return options_.get<composer_v1::EnvironmentsBackoffPolicyOption>()
        ->clone();
  }

  std::unique_ptr<composer_v1::EnvironmentsConnectionIdempotencyPolicy>
  idempotency_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<
            composer_v1::EnvironmentsConnectionIdempotencyPolicyOption>()) {
      return options
          .get<composer_v1::EnvironmentsConnectionIdempotencyPolicyOption>()
          ->clone();
    }
    return options_
        .get<composer_v1::EnvironmentsConnectionIdempotencyPolicyOption>()
        ->clone();
  }

  std::unique_ptr<PollingPolicy> polling_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<composer_v1::EnvironmentsPollingPolicyOption>()) {
      return options.get<composer_v1::EnvironmentsPollingPolicyOption>()
          ->clone();
    }
    return options_.get<composer_v1::EnvironmentsPollingPolicyOption>()
        ->clone();
  }

  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<composer_v1_internal::EnvironmentsStub> stub_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace composer_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_COMPOSER_V1_INTERNAL_ENVIRONMENTS_CONNECTION_IMPL_H
