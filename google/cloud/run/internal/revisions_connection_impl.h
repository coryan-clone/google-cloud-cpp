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
// source: google/cloud/run/v2/revision.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RUN_INTERNAL_REVISIONS_CONNECTION_IMPL_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RUN_INTERNAL_REVISIONS_CONNECTION_IMPL_H

#include "google/cloud/run/internal/revisions_retry_traits.h"
#include "google/cloud/run/internal/revisions_stub.h"
#include "google/cloud/run/revisions_connection.h"
#include "google/cloud/run/revisions_connection_idempotency_policy.h"
#include "google/cloud/run/revisions_options.h"
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
namespace run_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class RevisionsConnectionImpl : public run::RevisionsConnection {
 public:
  ~RevisionsConnectionImpl() override = default;

  RevisionsConnectionImpl(
      std::unique_ptr<google::cloud::BackgroundThreads> background,
      std::shared_ptr<run_internal::RevisionsStub> stub, Options options);

  Options options() override { return options_; }

  StatusOr<google::cloud::run::v2::Revision> GetRevision(
      google::cloud::run::v2::GetRevisionRequest const& request) override;

  StreamRange<google::cloud::run::v2::Revision> ListRevisions(
      google::cloud::run::v2::ListRevisionsRequest request) override;

  future<StatusOr<google::cloud::run::v2::Revision>> DeleteRevision(
      google::cloud::run::v2::DeleteRevisionRequest const& request) override;

 private:
  std::unique_ptr<run::RevisionsRetryPolicy> retry_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<run::RevisionsRetryPolicyOption>()) {
      return options.get<run::RevisionsRetryPolicyOption>()->clone();
    }
    return options_.get<run::RevisionsRetryPolicyOption>()->clone();
  }

  std::unique_ptr<BackoffPolicy> backoff_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<run::RevisionsBackoffPolicyOption>()) {
      return options.get<run::RevisionsBackoffPolicyOption>()->clone();
    }
    return options_.get<run::RevisionsBackoffPolicyOption>()->clone();
  }

  std::unique_ptr<run::RevisionsConnectionIdempotencyPolicy>
  idempotency_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<run::RevisionsConnectionIdempotencyPolicyOption>()) {
      return options.get<run::RevisionsConnectionIdempotencyPolicyOption>()
          ->clone();
    }
    return options_.get<run::RevisionsConnectionIdempotencyPolicyOption>()
        ->clone();
  }

  std::unique_ptr<PollingPolicy> polling_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<run::RevisionsPollingPolicyOption>()) {
      return options.get<run::RevisionsPollingPolicyOption>()->clone();
    }
    return options_.get<run::RevisionsPollingPolicyOption>()->clone();
  }

  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<run_internal::RevisionsStub> stub_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace run_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RUN_INTERNAL_REVISIONS_CONNECTION_IMPL_H
