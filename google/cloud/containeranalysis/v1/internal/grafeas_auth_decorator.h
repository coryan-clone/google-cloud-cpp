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
// source: grafeas/v1/grafeas.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CONTAINERANALYSIS_V1_INTERNAL_GRAFEAS_AUTH_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CONTAINERANALYSIS_V1_INTERNAL_GRAFEAS_AUTH_DECORATOR_H

#include "google/cloud/containeranalysis/v1/internal/grafeas_stub.h"
#include "google/cloud/internal/unified_grpc_credentials.h"
#include "google/cloud/version.h"
#include <memory>
#include <set>
#include <string>

namespace google {
namespace cloud {
namespace containeranalysis_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class GrafeasAuth : public GrafeasStub {
 public:
  ~GrafeasAuth() override = default;
  GrafeasAuth(
      std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
      std::shared_ptr<GrafeasStub> child);

  StatusOr<grafeas::v1::Occurrence> GetOccurrence(
      grpc::ClientContext& context,
      grafeas::v1::GetOccurrenceRequest const& request) override;

  StatusOr<grafeas::v1::ListOccurrencesResponse> ListOccurrences(
      grpc::ClientContext& context,
      grafeas::v1::ListOccurrencesRequest const& request) override;

  Status DeleteOccurrence(
      grpc::ClientContext& context,
      grafeas::v1::DeleteOccurrenceRequest const& request) override;

  StatusOr<grafeas::v1::Occurrence> CreateOccurrence(
      grpc::ClientContext& context,
      grafeas::v1::CreateOccurrenceRequest const& request) override;

  StatusOr<grafeas::v1::BatchCreateOccurrencesResponse> BatchCreateOccurrences(
      grpc::ClientContext& context,
      grafeas::v1::BatchCreateOccurrencesRequest const& request) override;

  StatusOr<grafeas::v1::Occurrence> UpdateOccurrence(
      grpc::ClientContext& context,
      grafeas::v1::UpdateOccurrenceRequest const& request) override;

  StatusOr<grafeas::v1::Note> GetOccurrenceNote(
      grpc::ClientContext& context,
      grafeas::v1::GetOccurrenceNoteRequest const& request) override;

  StatusOr<grafeas::v1::Note> GetNote(
      grpc::ClientContext& context,
      grafeas::v1::GetNoteRequest const& request) override;

  StatusOr<grafeas::v1::ListNotesResponse> ListNotes(
      grpc::ClientContext& context,
      grafeas::v1::ListNotesRequest const& request) override;

  Status DeleteNote(grpc::ClientContext& context,
                    grafeas::v1::DeleteNoteRequest const& request) override;

  StatusOr<grafeas::v1::Note> CreateNote(
      grpc::ClientContext& context,
      grafeas::v1::CreateNoteRequest const& request) override;

  StatusOr<grafeas::v1::BatchCreateNotesResponse> BatchCreateNotes(
      grpc::ClientContext& context,
      grafeas::v1::BatchCreateNotesRequest const& request) override;

  StatusOr<grafeas::v1::Note> UpdateNote(
      grpc::ClientContext& context,
      grafeas::v1::UpdateNoteRequest const& request) override;

  StatusOr<grafeas::v1::ListNoteOccurrencesResponse> ListNoteOccurrences(
      grpc::ClientContext& context,
      grafeas::v1::ListNoteOccurrencesRequest const& request) override;

 private:
  std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth_;
  std::shared_ptr<GrafeasStub> child_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace containeranalysis_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CONTAINERANALYSIS_V1_INTERNAL_GRAFEAS_AUTH_DECORATOR_H
