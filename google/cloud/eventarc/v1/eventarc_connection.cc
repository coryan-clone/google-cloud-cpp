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
// source: google/cloud/eventarc/v1/eventarc.proto

#include "google/cloud/eventarc/v1/eventarc_connection.h"
#include "google/cloud/eventarc/v1/eventarc_options.h"
#include "google/cloud/eventarc/v1/internal/eventarc_connection_impl.h"
#include "google/cloud/eventarc/v1/internal/eventarc_option_defaults.h"
#include "google/cloud/eventarc/v1/internal/eventarc_stub_factory.h"
#include "google/cloud/eventarc/v1/internal/eventarc_tracing_connection.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/credentials.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace eventarc_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

EventarcConnection::~EventarcConnection() = default;

StatusOr<google::cloud::eventarc::v1::Trigger> EventarcConnection::GetTrigger(
    google::cloud::eventarc::v1::GetTriggerRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::cloud::eventarc::v1::Trigger>
EventarcConnection::ListTriggers(
    google::cloud::eventarc::v1::
        ListTriggersRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::eventarc::v1::Trigger>>();
}

future<StatusOr<google::cloud::eventarc::v1::Trigger>>
EventarcConnection::CreateTrigger(
    google::cloud::eventarc::v1::CreateTriggerRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::eventarc::v1::Trigger>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::eventarc::v1::Trigger>>
EventarcConnection::UpdateTrigger(
    google::cloud::eventarc::v1::UpdateTriggerRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::eventarc::v1::Trigger>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::eventarc::v1::Trigger>>
EventarcConnection::DeleteTrigger(
    google::cloud::eventarc::v1::DeleteTriggerRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::eventarc::v1::Trigger>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StatusOr<google::cloud::eventarc::v1::Channel> EventarcConnection::GetChannel(
    google::cloud::eventarc::v1::GetChannelRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::cloud::eventarc::v1::Channel>
EventarcConnection::ListChannels(
    google::cloud::eventarc::v1::
        ListChannelsRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::eventarc::v1::Channel>>();
}

future<StatusOr<google::cloud::eventarc::v1::Channel>>
EventarcConnection::CreateChannel(
    google::cloud::eventarc::v1::CreateChannelRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::eventarc::v1::Channel>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::eventarc::v1::Channel>>
EventarcConnection::UpdateChannel(
    google::cloud::eventarc::v1::UpdateChannelRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::eventarc::v1::Channel>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::eventarc::v1::Channel>>
EventarcConnection::DeleteChannel(
    google::cloud::eventarc::v1::DeleteChannelRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::eventarc::v1::Channel>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StatusOr<google::cloud::eventarc::v1::Provider> EventarcConnection::GetProvider(
    google::cloud::eventarc::v1::GetProviderRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::cloud::eventarc::v1::Provider>
EventarcConnection::ListProviders(
    google::cloud::eventarc::v1::
        ListProvidersRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::eventarc::v1::Provider>>();
}

StatusOr<google::cloud::eventarc::v1::ChannelConnection>
EventarcConnection::GetChannelConnection(
    google::cloud::eventarc::v1::GetChannelConnectionRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::cloud::eventarc::v1::ChannelConnection>
EventarcConnection::ListChannelConnections(
    google::cloud::eventarc::v1::
        ListChannelConnectionsRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::eventarc::v1::ChannelConnection>>();
}

future<StatusOr<google::cloud::eventarc::v1::ChannelConnection>>
EventarcConnection::CreateChannelConnection(
    google::cloud::eventarc::v1::CreateChannelConnectionRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::eventarc::v1::ChannelConnection>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::eventarc::v1::ChannelConnection>>
EventarcConnection::DeleteChannelConnection(
    google::cloud::eventarc::v1::DeleteChannelConnectionRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::eventarc::v1::ChannelConnection>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StatusOr<google::cloud::eventarc::v1::GoogleChannelConfig>
EventarcConnection::GetGoogleChannelConfig(
    google::cloud::eventarc::v1::GetGoogleChannelConfigRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::eventarc::v1::GoogleChannelConfig>
EventarcConnection::UpdateGoogleChannelConfig(
    google::cloud::eventarc::v1::UpdateGoogleChannelConfigRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

std::shared_ptr<EventarcConnection> MakeEventarcConnection(Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 UnifiedCredentialsOptionList,
                                 EventarcPolicyOptionList>(options, __func__);
  options = eventarc_v1_internal::EventarcDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = eventarc_v1_internal::CreateDefaultEventarcStub(background->cq(),
                                                              options);
  return eventarc_v1_internal::MakeEventarcTracingConnection(
      std::make_shared<eventarc_v1_internal::EventarcConnectionImpl>(
          std::move(background), std::move(stub), std::move(options)));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace eventarc_v1
}  // namespace cloud
}  // namespace google
