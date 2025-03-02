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
// source: google/cloud/compute/networks/v1/networks.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_COMPUTE_NETWORKS_V1_INTERNAL_NETWORKS_REST_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_COMPUTE_NETWORKS_V1_INTERNAL_NETWORKS_REST_STUB_H

#include "google/cloud/completion_queue.h"
#include "google/cloud/internal/rest_client.h"
#include "google/cloud/internal/rest_context.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/cloud/compute/global_operations/v1/global_operations.pb.h>
#include <google/cloud/compute/networks/v1/networks.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace compute_networks_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class NetworksRestStub {
 public:
  virtual ~NetworksRestStub() = default;

  virtual future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
  AsyncAddPeering(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<google::cloud::rest_internal::RestContext> rest_context,
      google::cloud::cpp::compute::networks::v1::AddPeeringRequest const&
          request) = 0;

  virtual future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
  AsyncDeleteNetworks(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<google::cloud::rest_internal::RestContext> rest_context,
      google::cloud::cpp::compute::networks::v1::DeleteNetworksRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::cpp::compute::v1::Network> GetNetworks(
      google::cloud::rest_internal::RestContext& rest_context,
      google::cloud::cpp::compute::networks::v1::GetNetworksRequest const&
          request) = 0;

  virtual StatusOr<
      google::cloud::cpp::compute::v1::NetworksGetEffectiveFirewallsResponse>
  GetEffectiveFirewalls(google::cloud::rest_internal::RestContext& rest_context,
                        google::cloud::cpp::compute::networks::v1::
                            GetEffectiveFirewallsRequest const& request) = 0;

  virtual future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
  AsyncInsertNetworks(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<google::cloud::rest_internal::RestContext> rest_context,
      google::cloud::cpp::compute::networks::v1::InsertNetworksRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::cpp::compute::v1::NetworkList> ListNetworks(
      google::cloud::rest_internal::RestContext& rest_context,
      google::cloud::cpp::compute::networks::v1::ListNetworksRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::cpp::compute::v1::ExchangedPeeringRoutesList>
  ListPeeringRoutes(
      google::cloud::rest_internal::RestContext& rest_context,
      google::cloud::cpp::compute::networks::v1::ListPeeringRoutesRequest const&
          request) = 0;

  virtual future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
  AsyncPatchNetworks(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<google::cloud::rest_internal::RestContext> rest_context,
      google::cloud::cpp::compute::networks::v1::PatchNetworksRequest const&
          request) = 0;

  virtual future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
  AsyncRemovePeering(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<google::cloud::rest_internal::RestContext> rest_context,
      google::cloud::cpp::compute::networks::v1::RemovePeeringRequest const&
          request) = 0;

  virtual future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
  AsyncSwitchToCustomMode(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<google::cloud::rest_internal::RestContext> rest_context,
      google::cloud::cpp::compute::networks::v1::
          SwitchToCustomModeRequest const& request) = 0;

  virtual future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
  AsyncUpdatePeering(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<google::cloud::rest_internal::RestContext> rest_context,
      google::cloud::cpp::compute::networks::v1::UpdatePeeringRequest const&
          request) = 0;

  virtual future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
  AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<google::cloud::rest_internal::RestContext> rest_context,
      google::cloud::cpp::compute::global_operations::v1::
          GetGlobalOperationsRequest const& request) = 0;

  virtual future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<google::cloud::rest_internal::RestContext> rest_context,
      google::cloud::cpp::compute::global_operations::v1::
          DeleteGlobalOperationsRequest const& request) = 0;
};

class DefaultNetworksRestStub : public NetworksRestStub {
 public:
  ~DefaultNetworksRestStub() override = default;

  explicit DefaultNetworksRestStub(Options options);
  DefaultNetworksRestStub(std::shared_ptr<rest_internal::RestClient> service,
                          std::shared_ptr<rest_internal::RestClient> operations,
                          Options options);

  future<StatusOr<google::cloud::cpp::compute::v1::Operation>> AsyncAddPeering(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<google::cloud::rest_internal::RestContext> rest_context,
      google::cloud::cpp::compute::networks::v1::AddPeeringRequest const&
          request) override;

  future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
  AsyncDeleteNetworks(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<google::cloud::rest_internal::RestContext> rest_context,
      google::cloud::cpp::compute::networks::v1::DeleteNetworksRequest const&
          request) override;

  StatusOr<google::cloud::cpp::compute::v1::Network> GetNetworks(
      google::cloud::rest_internal::RestContext& rest_context,
      google::cloud::cpp::compute::networks::v1::GetNetworksRequest const&
          request) override;

  StatusOr<
      google::cloud::cpp::compute::v1::NetworksGetEffectiveFirewallsResponse>
  GetEffectiveFirewalls(
      google::cloud::rest_internal::RestContext& rest_context,
      google::cloud::cpp::compute::networks::v1::
          GetEffectiveFirewallsRequest const& request) override;

  future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
  AsyncInsertNetworks(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<google::cloud::rest_internal::RestContext> rest_context,
      google::cloud::cpp::compute::networks::v1::InsertNetworksRequest const&
          request) override;

  StatusOr<google::cloud::cpp::compute::v1::NetworkList> ListNetworks(
      google::cloud::rest_internal::RestContext& rest_context,
      google::cloud::cpp::compute::networks::v1::ListNetworksRequest const&
          request) override;

  StatusOr<google::cloud::cpp::compute::v1::ExchangedPeeringRoutesList>
  ListPeeringRoutes(
      google::cloud::rest_internal::RestContext& rest_context,
      google::cloud::cpp::compute::networks::v1::ListPeeringRoutesRequest const&
          request) override;

  future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
  AsyncPatchNetworks(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<google::cloud::rest_internal::RestContext> rest_context,
      google::cloud::cpp::compute::networks::v1::PatchNetworksRequest const&
          request) override;

  future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
  AsyncRemovePeering(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<google::cloud::rest_internal::RestContext> rest_context,
      google::cloud::cpp::compute::networks::v1::RemovePeeringRequest const&
          request) override;

  future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
  AsyncSwitchToCustomMode(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<google::cloud::rest_internal::RestContext> rest_context,
      google::cloud::cpp::compute::networks::v1::
          SwitchToCustomModeRequest const& request) override;

  future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
  AsyncUpdatePeering(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<google::cloud::rest_internal::RestContext> rest_context,
      google::cloud::cpp::compute::networks::v1::UpdatePeeringRequest const&
          request) override;

  future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
  AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<google::cloud::rest_internal::RestContext> rest_context,
      google::cloud::cpp::compute::global_operations::v1::
          GetGlobalOperationsRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<google::cloud::rest_internal::RestContext> rest_context,
      google::cloud::cpp::compute::global_operations::v1::
          DeleteGlobalOperationsRequest const& request) override;

 private:
  std::shared_ptr<rest_internal::RestClient> service_;
  std::shared_ptr<rest_internal::RestClient> operations_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace compute_networks_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_COMPUTE_NETWORKS_V1_INTERNAL_NETWORKS_REST_STUB_H
