// Copyright 2021 Google LLC
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
// source: google/cloud/pubsublite/v1/admin.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUBLITE_MOCKS_MOCK_ADMIN_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUBLITE_MOCKS_MOCK_ADMIN_CONNECTION_H

#include "google/cloud/pubsublite/admin_connection.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace pubsublite_mocks {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/**
 * A class to mock `AdminServiceConnection`.
 *
 * Application developers may want to test their code with simulated responses,
 * including errors, from an object of type `AdminServiceClient`. To do so,
 * construct an object of type `AdminServiceClient` with an instance of this
 * class. Then use the Google Test framework functions to program the behavior
 * of this mock.
 *
 * @see [This example][bq-mock] for how to test your application with GoogleTest.
 * While the example showcases types from the BigQuery library, the underlying
 * principles apply for any pair of `*Client` and `*Connection`.
 *
 * [bq-mock]: @cloud_cpp_docs_link{bigquery,bigquery-read-mock}
 */
class MockAdminServiceConnection : public pubsublite::AdminServiceConnection {
 public:
  MOCK_METHOD(Options, options, (), (override));

  MOCK_METHOD(
      StatusOr<google::cloud::pubsublite::v1::Topic>, CreateTopic,
      (google::cloud::pubsublite::v1::CreateTopicRequest const& request),
      (override));

  MOCK_METHOD(StatusOr<google::cloud::pubsublite::v1::Topic>, GetTopic,
              (google::cloud::pubsublite::v1::GetTopicRequest const& request),
              (override));

  MOCK_METHOD(
      StatusOr<google::cloud::pubsublite::v1::TopicPartitions>,
      GetTopicPartitions,
      (google::cloud::pubsublite::v1::GetTopicPartitionsRequest const& request),
      (override));

  MOCK_METHOD(StreamRange<google::cloud::pubsublite::v1::Topic>, ListTopics,
              (google::cloud::pubsublite::v1::ListTopicsRequest request),
              (override));

  MOCK_METHOD(
      StatusOr<google::cloud::pubsublite::v1::Topic>, UpdateTopic,
      (google::cloud::pubsublite::v1::UpdateTopicRequest const& request),
      (override));

  MOCK_METHOD(
      Status, DeleteTopic,
      (google::cloud::pubsublite::v1::DeleteTopicRequest const& request),
      (override));

  MOCK_METHOD(
      StreamRange<std::string>, ListTopicSubscriptions,
      (google::cloud::pubsublite::v1::ListTopicSubscriptionsRequest request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::pubsublite::v1::Subscription>, CreateSubscription,
      (google::cloud::pubsublite::v1::CreateSubscriptionRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::pubsublite::v1::Subscription>, GetSubscription,
      (google::cloud::pubsublite::v1::GetSubscriptionRequest const& request),
      (override));

  MOCK_METHOD(StreamRange<google::cloud::pubsublite::v1::Subscription>,
              ListSubscriptions,
              (google::cloud::pubsublite::v1::ListSubscriptionsRequest request),
              (override));

  MOCK_METHOD(
      StatusOr<google::cloud::pubsublite::v1::Subscription>, UpdateSubscription,
      (google::cloud::pubsublite::v1::UpdateSubscriptionRequest const& request),
      (override));

  MOCK_METHOD(
      Status, DeleteSubscription,
      (google::cloud::pubsublite::v1::DeleteSubscriptionRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::pubsublite::v1::SeekSubscriptionResponse>>,
      SeekSubscription,
      (google::cloud::pubsublite::v1::SeekSubscriptionRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::pubsublite::v1::Reservation>, CreateReservation,
      (google::cloud::pubsublite::v1::CreateReservationRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::pubsublite::v1::Reservation>, GetReservation,
      (google::cloud::pubsublite::v1::GetReservationRequest const& request),
      (override));

  MOCK_METHOD(StreamRange<google::cloud::pubsublite::v1::Reservation>,
              ListReservations,
              (google::cloud::pubsublite::v1::ListReservationsRequest request),
              (override));

  MOCK_METHOD(
      StatusOr<google::cloud::pubsublite::v1::Reservation>, UpdateReservation,
      (google::cloud::pubsublite::v1::UpdateReservationRequest const& request),
      (override));

  MOCK_METHOD(
      Status, DeleteReservation,
      (google::cloud::pubsublite::v1::DeleteReservationRequest const& request),
      (override));

  MOCK_METHOD(
      StreamRange<std::string>, ListReservationTopics,
      (google::cloud::pubsublite::v1::ListReservationTopicsRequest request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::pubsublite::v1::TopicPartitions>>,
      AsyncGetTopicPartitions,
      (google::cloud::pubsublite::v1::GetTopicPartitionsRequest const& request),
      (override));
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsublite_mocks
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUBLITE_MOCKS_MOCK_ADMIN_CONNECTION_H
