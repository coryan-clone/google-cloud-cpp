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
// source:
// google/cloud/beyondcorp/clientconnectorservices/v1/client_connector_services_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BEYONDCORP_CLIENTCONNECTORSERVICES_V1_INTERNAL_CLIENT_CONNECTOR_SERVICES_AUTH_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BEYONDCORP_CLIENTCONNECTORSERVICES_V1_INTERNAL_CLIENT_CONNECTOR_SERVICES_AUTH_DECORATOR_H

#include "google/cloud/beyondcorp/clientconnectorservices/v1/internal/client_connector_services_stub.h"
#include "google/cloud/internal/unified_grpc_credentials.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>
#include <set>
#include <string>

namespace google {
namespace cloud {
namespace beyondcorp_clientconnectorservices_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class ClientConnectorServicesServiceAuth
    : public ClientConnectorServicesServiceStub {
 public:
  ~ClientConnectorServicesServiceAuth() override = default;
  ClientConnectorServicesServiceAuth(
      std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
      std::shared_ptr<ClientConnectorServicesServiceStub> child);

  StatusOr<google::cloud::beyondcorp::clientconnectorservices::v1::
               ListClientConnectorServicesResponse>
  ListClientConnectorServices(
      grpc::ClientContext& context,
      google::cloud::beyondcorp::clientconnectorservices::v1::
          ListClientConnectorServicesRequest const& request) override;

  StatusOr<google::cloud::beyondcorp::clientconnectorservices::v1::
               ClientConnectorService>
  GetClientConnectorService(
      grpc::ClientContext& context,
      google::cloud::beyondcorp::clientconnectorservices::v1::
          GetClientConnectorServiceRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncCreateClientConnectorService(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::beyondcorp::clientconnectorservices::v1::
          CreateClientConnectorServiceRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncUpdateClientConnectorService(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::beyondcorp::clientconnectorservices::v1::
          UpdateClientConnectorServiceRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncDeleteClientConnectorService(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::beyondcorp::clientconnectorservices::v1::
          DeleteClientConnectorServiceRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth_;
  std::shared_ptr<ClientConnectorServicesServiceStub> child_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace beyondcorp_clientconnectorservices_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BEYONDCORP_CLIENTCONNECTORSERVICES_V1_INTERNAL_CLIENT_CONNECTOR_SERVICES_AUTH_DECORATOR_H
