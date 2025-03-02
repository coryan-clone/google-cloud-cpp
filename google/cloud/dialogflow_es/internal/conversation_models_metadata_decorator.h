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
// source: google/cloud/dialogflow/v2/conversation_model.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_INTERNAL_CONVERSATION_MODELS_METADATA_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_INTERNAL_CONVERSATION_MODELS_METADATA_DECORATOR_H

#include "google/cloud/dialogflow_es/internal/conversation_models_stub.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <map>
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace dialogflow_es_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class ConversationModelsMetadata : public ConversationModelsStub {
 public:
  ~ConversationModelsMetadata() override = default;
  ConversationModelsMetadata(
      std::shared_ptr<ConversationModelsStub> child,
      std::multimap<std::string, std::string> fixed_metadata);

  future<StatusOr<google::longrunning::Operation>> AsyncCreateConversationModel(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::dialogflow::v2::CreateConversationModelRequest const&
          request) override;

  StatusOr<google::cloud::dialogflow::v2::ConversationModel>
  GetConversationModel(
      grpc::ClientContext& context,
      google::cloud::dialogflow::v2::GetConversationModelRequest const& request)
      override;

  StatusOr<google::cloud::dialogflow::v2::ListConversationModelsResponse>
  ListConversationModels(
      grpc::ClientContext& context,
      google::cloud::dialogflow::v2::ListConversationModelsRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteConversationModel(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::dialogflow::v2::DeleteConversationModelRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeployConversationModel(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::dialogflow::v2::DeployConversationModelRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncUndeployConversationModel(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::dialogflow::v2::UndeployConversationModelRequest const&
          request) override;

  StatusOr<google::cloud::dialogflow::v2::ConversationModelEvaluation>
  GetConversationModelEvaluation(
      grpc::ClientContext& context,
      google::cloud::dialogflow::v2::
          GetConversationModelEvaluationRequest const& request) override;

  StatusOr<
      google::cloud::dialogflow::v2::ListConversationModelEvaluationsResponse>
  ListConversationModelEvaluations(
      grpc::ClientContext& context,
      google::cloud::dialogflow::v2::
          ListConversationModelEvaluationsRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncCreateConversationModelEvaluation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::dialogflow::v2::
          CreateConversationModelEvaluationRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  void SetMetadata(grpc::ClientContext& context,
                   std::string const& request_params);
  void SetMetadata(grpc::ClientContext& context);

  std::shared_ptr<ConversationModelsStub> child_;
  std::multimap<std::string, std::string> fixed_metadata_;
  std::string api_client_header_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_INTERNAL_CONVERSATION_MODELS_METADATA_DECORATOR_H
