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
// source: google/cloud/aiplatform/v1/model_service.proto

#include "google/cloud/aiplatform/v1/internal/model_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/status_or.h"
#include <google/cloud/aiplatform/v1/model_service.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace aiplatform_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ModelServiceMetadata::ModelServiceMetadata(
    std::shared_ptr<ModelServiceStub> child,
    std::multimap<std::string, std::string> fixed_metadata)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          google::cloud::internal::ApiClientHeader("generator")) {}

future<StatusOr<google::longrunning::Operation>>
ModelServiceMetadata::AsyncUploadModel(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::aiplatform::v1::UploadModelRequest const& request) {
  SetMetadata(*context, "parent=" + request.parent());
  return child_->AsyncUploadModel(cq, std::move(context), request);
}

StatusOr<google::cloud::aiplatform::v1::Model> ModelServiceMetadata::GetModel(
    grpc::ClientContext& context,
    google::cloud::aiplatform::v1::GetModelRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetModel(context, request);
}

StatusOr<google::cloud::aiplatform::v1::ListModelsResponse>
ModelServiceMetadata::ListModels(
    grpc::ClientContext& context,
    google::cloud::aiplatform::v1::ListModelsRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListModels(context, request);
}

StatusOr<google::cloud::aiplatform::v1::ListModelVersionsResponse>
ModelServiceMetadata::ListModelVersions(
    grpc::ClientContext& context,
    google::cloud::aiplatform::v1::ListModelVersionsRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->ListModelVersions(context, request);
}

StatusOr<google::cloud::aiplatform::v1::Model>
ModelServiceMetadata::UpdateModel(
    grpc::ClientContext& context,
    google::cloud::aiplatform::v1::UpdateModelRequest const& request) {
  SetMetadata(context, "model.name=" + request.model().name());
  return child_->UpdateModel(context, request);
}

future<StatusOr<google::longrunning::Operation>>
ModelServiceMetadata::AsyncUpdateExplanationDataset(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::aiplatform::v1::UpdateExplanationDatasetRequest const&
        request) {
  SetMetadata(*context, "model=" + request.model());
  return child_->AsyncUpdateExplanationDataset(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
ModelServiceMetadata::AsyncDeleteModel(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::aiplatform::v1::DeleteModelRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncDeleteModel(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
ModelServiceMetadata::AsyncDeleteModelVersion(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::aiplatform::v1::DeleteModelVersionRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncDeleteModelVersion(cq, std::move(context), request);
}

StatusOr<google::cloud::aiplatform::v1::Model>
ModelServiceMetadata::MergeVersionAliases(
    grpc::ClientContext& context,
    google::cloud::aiplatform::v1::MergeVersionAliasesRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->MergeVersionAliases(context, request);
}

future<StatusOr<google::longrunning::Operation>>
ModelServiceMetadata::AsyncExportModel(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::aiplatform::v1::ExportModelRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncExportModel(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
ModelServiceMetadata::AsyncCopyModel(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::aiplatform::v1::CopyModelRequest const& request) {
  SetMetadata(*context, "parent=" + request.parent());
  return child_->AsyncCopyModel(cq, std::move(context), request);
}

StatusOr<google::cloud::aiplatform::v1::ModelEvaluation>
ModelServiceMetadata::ImportModelEvaluation(
    grpc::ClientContext& context,
    google::cloud::aiplatform::v1::ImportModelEvaluationRequest const&
        request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ImportModelEvaluation(context, request);
}

StatusOr<
    google::cloud::aiplatform::v1::BatchImportModelEvaluationSlicesResponse>
ModelServiceMetadata::BatchImportModelEvaluationSlices(
    grpc::ClientContext& context,
    google::cloud::aiplatform::v1::
        BatchImportModelEvaluationSlicesRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->BatchImportModelEvaluationSlices(context, request);
}

StatusOr<google::cloud::aiplatform::v1::BatchImportEvaluatedAnnotationsResponse>
ModelServiceMetadata::BatchImportEvaluatedAnnotations(
    grpc::ClientContext& context,
    google::cloud::aiplatform::v1::BatchImportEvaluatedAnnotationsRequest const&
        request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->BatchImportEvaluatedAnnotations(context, request);
}

StatusOr<google::cloud::aiplatform::v1::ModelEvaluation>
ModelServiceMetadata::GetModelEvaluation(
    grpc::ClientContext& context,
    google::cloud::aiplatform::v1::GetModelEvaluationRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetModelEvaluation(context, request);
}

StatusOr<google::cloud::aiplatform::v1::ListModelEvaluationsResponse>
ModelServiceMetadata::ListModelEvaluations(
    grpc::ClientContext& context,
    google::cloud::aiplatform::v1::ListModelEvaluationsRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListModelEvaluations(context, request);
}

StatusOr<google::cloud::aiplatform::v1::ModelEvaluationSlice>
ModelServiceMetadata::GetModelEvaluationSlice(
    grpc::ClientContext& context,
    google::cloud::aiplatform::v1::GetModelEvaluationSliceRequest const&
        request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetModelEvaluationSlice(context, request);
}

StatusOr<google::cloud::aiplatform::v1::ListModelEvaluationSlicesResponse>
ModelServiceMetadata::ListModelEvaluationSlices(
    grpc::ClientContext& context,
    google::cloud::aiplatform::v1::ListModelEvaluationSlicesRequest const&
        request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListModelEvaluationSlices(context, request);
}

future<StatusOr<google::longrunning::Operation>>
ModelServiceMetadata::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncGetOperation(cq, std::move(context), request);
}

future<Status> ModelServiceMetadata::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncCancelOperation(cq, std::move(context), request);
}

void ModelServiceMetadata::SetMetadata(grpc::ClientContext& context,
                                       std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context);
}

void ModelServiceMetadata::SetMetadata(grpc::ClientContext& context) {
  for (auto const& kv : fixed_metadata_) {
    context.AddMetadata(kv.first, kv.second);
  }
  context.AddMetadata("x-goog-api-client", api_client_header_);
  auto const& options = internal::CurrentOptions();
  if (options.has<UserProjectOption>()) {
    context.AddMetadata("x-goog-user-project",
                        options.get<UserProjectOption>());
  }
  auto const& authority = options.get<AuthorityOption>();
  if (!authority.empty()) context.set_authority(authority);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace aiplatform_v1_internal
}  // namespace cloud
}  // namespace google
