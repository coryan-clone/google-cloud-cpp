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
// source: google/cloud/video/stitcher/v1/video_stitcher_service.proto

#include "google/cloud/video/stitcher/v1/internal/video_stitcher_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/status_or.h"
#include <google/cloud/video/stitcher/v1/video_stitcher_service.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace video_stitcher_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

VideoStitcherServiceMetadata::VideoStitcherServiceMetadata(
    std::shared_ptr<VideoStitcherServiceStub> child,
    std::multimap<std::string, std::string> fixed_metadata)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          google::cloud::internal::ApiClientHeader("generator")) {}

future<StatusOr<google::longrunning::Operation>>
VideoStitcherServiceMetadata::AsyncCreateCdnKey(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::video::stitcher::v1::CreateCdnKeyRequest const& request) {
  SetMetadata(*context, "parent=" + request.parent());
  return child_->AsyncCreateCdnKey(cq, std::move(context), request);
}

StatusOr<google::cloud::video::stitcher::v1::ListCdnKeysResponse>
VideoStitcherServiceMetadata::ListCdnKeys(
    grpc::ClientContext& context,
    google::cloud::video::stitcher::v1::ListCdnKeysRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListCdnKeys(context, request);
}

StatusOr<google::cloud::video::stitcher::v1::CdnKey>
VideoStitcherServiceMetadata::GetCdnKey(
    grpc::ClientContext& context,
    google::cloud::video::stitcher::v1::GetCdnKeyRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetCdnKey(context, request);
}

future<StatusOr<google::longrunning::Operation>>
VideoStitcherServiceMetadata::AsyncDeleteCdnKey(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::video::stitcher::v1::DeleteCdnKeyRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncDeleteCdnKey(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
VideoStitcherServiceMetadata::AsyncUpdateCdnKey(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::video::stitcher::v1::UpdateCdnKeyRequest const& request) {
  SetMetadata(*context, "cdn_key.name=" + request.cdn_key().name());
  return child_->AsyncUpdateCdnKey(cq, std::move(context), request);
}

StatusOr<google::cloud::video::stitcher::v1::VodSession>
VideoStitcherServiceMetadata::CreateVodSession(
    grpc::ClientContext& context,
    google::cloud::video::stitcher::v1::CreateVodSessionRequest const&
        request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->CreateVodSession(context, request);
}

StatusOr<google::cloud::video::stitcher::v1::VodSession>
VideoStitcherServiceMetadata::GetVodSession(
    grpc::ClientContext& context,
    google::cloud::video::stitcher::v1::GetVodSessionRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetVodSession(context, request);
}

StatusOr<google::cloud::video::stitcher::v1::ListVodStitchDetailsResponse>
VideoStitcherServiceMetadata::ListVodStitchDetails(
    grpc::ClientContext& context,
    google::cloud::video::stitcher::v1::ListVodStitchDetailsRequest const&
        request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListVodStitchDetails(context, request);
}

StatusOr<google::cloud::video::stitcher::v1::VodStitchDetail>
VideoStitcherServiceMetadata::GetVodStitchDetail(
    grpc::ClientContext& context,
    google::cloud::video::stitcher::v1::GetVodStitchDetailRequest const&
        request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetVodStitchDetail(context, request);
}

StatusOr<google::cloud::video::stitcher::v1::ListVodAdTagDetailsResponse>
VideoStitcherServiceMetadata::ListVodAdTagDetails(
    grpc::ClientContext& context,
    google::cloud::video::stitcher::v1::ListVodAdTagDetailsRequest const&
        request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListVodAdTagDetails(context, request);
}

StatusOr<google::cloud::video::stitcher::v1::VodAdTagDetail>
VideoStitcherServiceMetadata::GetVodAdTagDetail(
    grpc::ClientContext& context,
    google::cloud::video::stitcher::v1::GetVodAdTagDetailRequest const&
        request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetVodAdTagDetail(context, request);
}

StatusOr<google::cloud::video::stitcher::v1::ListLiveAdTagDetailsResponse>
VideoStitcherServiceMetadata::ListLiveAdTagDetails(
    grpc::ClientContext& context,
    google::cloud::video::stitcher::v1::ListLiveAdTagDetailsRequest const&
        request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListLiveAdTagDetails(context, request);
}

StatusOr<google::cloud::video::stitcher::v1::LiveAdTagDetail>
VideoStitcherServiceMetadata::GetLiveAdTagDetail(
    grpc::ClientContext& context,
    google::cloud::video::stitcher::v1::GetLiveAdTagDetailRequest const&
        request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetLiveAdTagDetail(context, request);
}

future<StatusOr<google::longrunning::Operation>>
VideoStitcherServiceMetadata::AsyncCreateSlate(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::video::stitcher::v1::CreateSlateRequest const& request) {
  SetMetadata(*context, "parent=" + request.parent());
  return child_->AsyncCreateSlate(cq, std::move(context), request);
}

StatusOr<google::cloud::video::stitcher::v1::ListSlatesResponse>
VideoStitcherServiceMetadata::ListSlates(
    grpc::ClientContext& context,
    google::cloud::video::stitcher::v1::ListSlatesRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListSlates(context, request);
}

StatusOr<google::cloud::video::stitcher::v1::Slate>
VideoStitcherServiceMetadata::GetSlate(
    grpc::ClientContext& context,
    google::cloud::video::stitcher::v1::GetSlateRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetSlate(context, request);
}

future<StatusOr<google::longrunning::Operation>>
VideoStitcherServiceMetadata::AsyncUpdateSlate(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::video::stitcher::v1::UpdateSlateRequest const& request) {
  SetMetadata(*context, "slate.name=" + request.slate().name());
  return child_->AsyncUpdateSlate(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
VideoStitcherServiceMetadata::AsyncDeleteSlate(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::video::stitcher::v1::DeleteSlateRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncDeleteSlate(cq, std::move(context), request);
}

StatusOr<google::cloud::video::stitcher::v1::LiveSession>
VideoStitcherServiceMetadata::CreateLiveSession(
    grpc::ClientContext& context,
    google::cloud::video::stitcher::v1::CreateLiveSessionRequest const&
        request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->CreateLiveSession(context, request);
}

StatusOr<google::cloud::video::stitcher::v1::LiveSession>
VideoStitcherServiceMetadata::GetLiveSession(
    grpc::ClientContext& context,
    google::cloud::video::stitcher::v1::GetLiveSessionRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetLiveSession(context, request);
}

future<StatusOr<google::longrunning::Operation>>
VideoStitcherServiceMetadata::AsyncCreateLiveConfig(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::video::stitcher::v1::CreateLiveConfigRequest const&
        request) {
  SetMetadata(*context, "parent=" + request.parent());
  return child_->AsyncCreateLiveConfig(cq, std::move(context), request);
}

StatusOr<google::cloud::video::stitcher::v1::ListLiveConfigsResponse>
VideoStitcherServiceMetadata::ListLiveConfigs(
    grpc::ClientContext& context,
    google::cloud::video::stitcher::v1::ListLiveConfigsRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListLiveConfigs(context, request);
}

StatusOr<google::cloud::video::stitcher::v1::LiveConfig>
VideoStitcherServiceMetadata::GetLiveConfig(
    grpc::ClientContext& context,
    google::cloud::video::stitcher::v1::GetLiveConfigRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetLiveConfig(context, request);
}

future<StatusOr<google::longrunning::Operation>>
VideoStitcherServiceMetadata::AsyncDeleteLiveConfig(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::video::stitcher::v1::DeleteLiveConfigRequest const&
        request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncDeleteLiveConfig(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
VideoStitcherServiceMetadata::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncGetOperation(cq, std::move(context), request);
}

future<Status> VideoStitcherServiceMetadata::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncCancelOperation(cq, std::move(context), request);
}

void VideoStitcherServiceMetadata::SetMetadata(
    grpc::ClientContext& context, std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context);
}

void VideoStitcherServiceMetadata::SetMetadata(grpc::ClientContext& context) {
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
}  // namespace video_stitcher_v1_internal
}  // namespace cloud
}  // namespace google
