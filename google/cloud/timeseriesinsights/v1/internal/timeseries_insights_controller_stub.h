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
// source: google/cloud/timeseriesinsights/v1/timeseries_insights.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_TIMESERIESINSIGHTS_V1_INTERNAL_TIMESERIES_INSIGHTS_CONTROLLER_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_TIMESERIESINSIGHTS_V1_INTERNAL_TIMESERIES_INSIGHTS_CONTROLLER_STUB_H

#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/cloud/timeseriesinsights/v1/timeseries_insights.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace timeseriesinsights_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class TimeseriesInsightsControllerStub {
 public:
  virtual ~TimeseriesInsightsControllerStub() = 0;

  virtual StatusOr<google::cloud::timeseriesinsights::v1::ListDataSetsResponse>
  ListDataSets(grpc::ClientContext& context,
               google::cloud::timeseriesinsights::v1::ListDataSetsRequest const&
                   request) = 0;

  virtual StatusOr<google::cloud::timeseriesinsights::v1::DataSet>
  CreateDataSet(
      grpc::ClientContext& context,
      google::cloud::timeseriesinsights::v1::CreateDataSetRequest const&
          request) = 0;

  virtual Status DeleteDataSet(
      grpc::ClientContext& context,
      google::cloud::timeseriesinsights::v1::DeleteDataSetRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::timeseriesinsights::v1::AppendEventsResponse>
  AppendEvents(grpc::ClientContext& context,
               google::cloud::timeseriesinsights::v1::AppendEventsRequest const&
                   request) = 0;

  virtual StatusOr<google::cloud::timeseriesinsights::v1::QueryDataSetResponse>
  QueryDataSet(grpc::ClientContext& context,
               google::cloud::timeseriesinsights::v1::QueryDataSetRequest const&
                   request) = 0;

  virtual StatusOr<google::cloud::timeseriesinsights::v1::EvaluatedSlice>
  EvaluateSlice(
      grpc::ClientContext& context,
      google::cloud::timeseriesinsights::v1::EvaluateSliceRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::timeseriesinsights::v1::EvaluatedSlice>
  EvaluateTimeseries(
      grpc::ClientContext& context,
      google::cloud::timeseriesinsights::v1::EvaluateTimeseriesRequest const&
          request) = 0;
};

class DefaultTimeseriesInsightsControllerStub
    : public TimeseriesInsightsControllerStub {
 public:
  explicit DefaultTimeseriesInsightsControllerStub(
      std::unique_ptr<google::cloud::timeseriesinsights::v1::
                          TimeseriesInsightsController::StubInterface>
          grpc_stub)
      : grpc_stub_(std::move(grpc_stub)) {}

  StatusOr<google::cloud::timeseriesinsights::v1::ListDataSetsResponse>
  ListDataSets(grpc::ClientContext& client_context,
               google::cloud::timeseriesinsights::v1::ListDataSetsRequest const&
                   request) override;

  StatusOr<google::cloud::timeseriesinsights::v1::DataSet> CreateDataSet(
      grpc::ClientContext& client_context,
      google::cloud::timeseriesinsights::v1::CreateDataSetRequest const&
          request) override;

  Status DeleteDataSet(
      grpc::ClientContext& client_context,
      google::cloud::timeseriesinsights::v1::DeleteDataSetRequest const&
          request) override;

  StatusOr<google::cloud::timeseriesinsights::v1::AppendEventsResponse>
  AppendEvents(grpc::ClientContext& client_context,
               google::cloud::timeseriesinsights::v1::AppendEventsRequest const&
                   request) override;

  StatusOr<google::cloud::timeseriesinsights::v1::QueryDataSetResponse>
  QueryDataSet(grpc::ClientContext& client_context,
               google::cloud::timeseriesinsights::v1::QueryDataSetRequest const&
                   request) override;

  StatusOr<google::cloud::timeseriesinsights::v1::EvaluatedSlice> EvaluateSlice(
      grpc::ClientContext& client_context,
      google::cloud::timeseriesinsights::v1::EvaluateSliceRequest const&
          request) override;

  StatusOr<google::cloud::timeseriesinsights::v1::EvaluatedSlice>
  EvaluateTimeseries(
      grpc::ClientContext& client_context,
      google::cloud::timeseriesinsights::v1::EvaluateTimeseriesRequest const&
          request) override;

 private:
  std::unique_ptr<google::cloud::timeseriesinsights::v1::
                      TimeseriesInsightsController::StubInterface>
      grpc_stub_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace timeseriesinsights_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_TIMESERIESINSIGHTS_V1_INTERNAL_TIMESERIES_INSIGHTS_CONTROLLER_STUB_H
