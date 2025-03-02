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
// source: google/cloud/dialogflow/cx/v3/webhook.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_WEBHOOKS_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_WEBHOOKS_CLIENT_H

#include "google/cloud/dialogflow_cx/webhooks_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_cx {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Service for managing [Webhooks][google.cloud.dialogflow.cx.v3.Webhook].
///
/// @par Equality
///
/// Instances of this class created via copy-construction or copy-assignment
/// always compare equal. Instances created with equal
/// `std::shared_ptr<*Connection>` objects compare equal. Objects that compare
/// equal share the same underlying resources.
///
/// @par Performance
///
/// Creating a new instance of this class is a relatively expensive operation,
/// new objects establish new connections to the service. In contrast,
/// copy-construction, move-construction, and the corresponding assignment
/// operations are relatively efficient as the copies share all underlying
/// resources.
///
/// @par Thread Safety
///
/// Concurrent access to different instances of this class, even if they compare
/// equal, is guaranteed to work. Two or more threads operating on the same
/// instance of this class is not guaranteed to work. Since copy-construction
/// and move-construction is a relatively efficient operation, consider using
/// such a copy when using this class from multiple threads.
///
/// [google.cloud.dialogflow.cx.v3.Webhook]:
/// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/webhook.proto#L96}
///
class WebhooksClient {
 public:
  explicit WebhooksClient(std::shared_ptr<WebhooksConnection> connection,
                          Options opts = {});
  ~WebhooksClient();

  ///@{
  /// @name Copy and move support
  WebhooksClient(WebhooksClient const&) = default;
  WebhooksClient& operator=(WebhooksClient const&) = default;
  WebhooksClient(WebhooksClient&&) = default;
  WebhooksClient& operator=(WebhooksClient&&) = default;
  ///@}

  ///@{
  /// @name Equality
  friend bool operator==(WebhooksClient const& a, WebhooksClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(WebhooksClient const& a, WebhooksClient const& b) {
    return !(a == b);
  }
  ///@}

  // clang-format off
  ///
  /// Returns the list of all webhooks in the specified agent.
  ///
  /// @param parent  Required. The agent to list all webhooks for.
  ///  Format: `projects/<Project ID>/locations/<Location ID>/agents/<Agent ID>`.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return a [StreamRange](@ref google::cloud::StreamRange)
  ///     to iterate of the results. See the documentation of this type for
  ///     details. In brief, this class has `begin()` and `end()` member
  ///     functions returning a iterator class meeting the
  ///     [input iterator requirements]. The value type for this iterator is a
  ///     [`StatusOr`] as the iteration may fail even after some values are
  ///     retrieved successfully, for example, if there is a network disconnect.
  ///     An empty set of results does not indicate an error, it indicates
  ///     that there are no resources meeting the request criteria.
  ///     On a successful iteration the `StatusOr<T>` contains elements of type
  ///     [google.cloud.dialogflow.cx.v3.Webhook], or rather,
  ///     the C++ class generated by Protobuf from that type. Please consult the
  ///     Protobuf documentation for details on the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.dialogflow.cx.v3.ListWebhooksRequest]: @googleapis_reference_link{google/cloud/dialogflow/cx/v3/webhook.proto#L244}
  /// [google.cloud.dialogflow.cx.v3.Webhook]: @googleapis_reference_link{google/cloud/dialogflow/cx/v3/webhook.proto#L96}
  ///
  // clang-format on
  StreamRange<google::cloud::dialogflow::cx::v3::Webhook> ListWebhooks(
      std::string const& parent, Options opts = {});

  // clang-format off
  ///
  /// Returns the list of all webhooks in the specified agent.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.dialogflow.cx.v3.ListWebhooksRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return a [StreamRange](@ref google::cloud::StreamRange)
  ///     to iterate of the results. See the documentation of this type for
  ///     details. In brief, this class has `begin()` and `end()` member
  ///     functions returning a iterator class meeting the
  ///     [input iterator requirements]. The value type for this iterator is a
  ///     [`StatusOr`] as the iteration may fail even after some values are
  ///     retrieved successfully, for example, if there is a network disconnect.
  ///     An empty set of results does not indicate an error, it indicates
  ///     that there are no resources meeting the request criteria.
  ///     On a successful iteration the `StatusOr<T>` contains elements of type
  ///     [google.cloud.dialogflow.cx.v3.Webhook], or rather,
  ///     the C++ class generated by Protobuf from that type. Please consult the
  ///     Protobuf documentation for details on the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.dialogflow.cx.v3.ListWebhooksRequest]: @googleapis_reference_link{google/cloud/dialogflow/cx/v3/webhook.proto#L244}
  /// [google.cloud.dialogflow.cx.v3.Webhook]: @googleapis_reference_link{google/cloud/dialogflow/cx/v3/webhook.proto#L96}
  ///
  // clang-format on
  StreamRange<google::cloud::dialogflow::cx::v3::Webhook> ListWebhooks(
      google::cloud::dialogflow::cx::v3::ListWebhooksRequest request,
      Options opts = {});

  // clang-format off
  ///
  /// Retrieves the specified webhook.
  ///
  /// @param name  Required. The name of the webhook.
  ///  Format: `projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>/webhooks/<Webhook ID>`.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.dialogflow.cx.v3.Webhook])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.dialogflow.cx.v3.GetWebhookRequest]: @googleapis_reference_link{google/cloud/dialogflow/cx/v3/webhook.proto#L276}
  /// [google.cloud.dialogflow.cx.v3.Webhook]: @googleapis_reference_link{google/cloud/dialogflow/cx/v3/webhook.proto#L96}
  ///
  // clang-format on
  StatusOr<google::cloud::dialogflow::cx::v3::Webhook> GetWebhook(
      std::string const& name, Options opts = {});

  // clang-format off
  ///
  /// Retrieves the specified webhook.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.dialogflow.cx.v3.GetWebhookRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.dialogflow.cx.v3.Webhook])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.dialogflow.cx.v3.GetWebhookRequest]: @googleapis_reference_link{google/cloud/dialogflow/cx/v3/webhook.proto#L276}
  /// [google.cloud.dialogflow.cx.v3.Webhook]: @googleapis_reference_link{google/cloud/dialogflow/cx/v3/webhook.proto#L96}
  ///
  // clang-format on
  StatusOr<google::cloud::dialogflow::cx::v3::Webhook> GetWebhook(
      google::cloud::dialogflow::cx::v3::GetWebhookRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Creates a webhook in the specified agent.
  ///
  /// @param parent  Required. The agent to create a webhook for.
  ///  Format: `projects/<Project ID>/locations/<Location ID>/agents/<Agent ID>`.
  /// @param webhook  Required. The webhook to create.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.dialogflow.cx.v3.Webhook])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.dialogflow.cx.v3.CreateWebhookRequest]: @googleapis_reference_link{google/cloud/dialogflow/cx/v3/webhook.proto#L290}
  /// [google.cloud.dialogflow.cx.v3.Webhook]: @googleapis_reference_link{google/cloud/dialogflow/cx/v3/webhook.proto#L96}
  ///
  // clang-format on
  StatusOr<google::cloud::dialogflow::cx::v3::Webhook> CreateWebhook(
      std::string const& parent,
      google::cloud::dialogflow::cx::v3::Webhook const& webhook,
      Options opts = {});

  // clang-format off
  ///
  /// Creates a webhook in the specified agent.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.dialogflow.cx.v3.CreateWebhookRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.dialogflow.cx.v3.Webhook])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.dialogflow.cx.v3.CreateWebhookRequest]: @googleapis_reference_link{google/cloud/dialogflow/cx/v3/webhook.proto#L290}
  /// [google.cloud.dialogflow.cx.v3.Webhook]: @googleapis_reference_link{google/cloud/dialogflow/cx/v3/webhook.proto#L96}
  ///
  // clang-format on
  StatusOr<google::cloud::dialogflow::cx::v3::Webhook> CreateWebhook(
      google::cloud::dialogflow::cx::v3::CreateWebhookRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Updates the specified webhook.
  ///
  /// @param webhook  Required. The webhook to update.
  /// @param update_mask  The mask to control which fields get updated. If the mask is not present,
  ///  all fields will be updated.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.dialogflow.cx.v3.Webhook])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.dialogflow.cx.v3.UpdateWebhookRequest]: @googleapis_reference_link{google/cloud/dialogflow/cx/v3/webhook.proto#L306}
  /// [google.cloud.dialogflow.cx.v3.Webhook]: @googleapis_reference_link{google/cloud/dialogflow/cx/v3/webhook.proto#L96}
  ///
  // clang-format on
  StatusOr<google::cloud::dialogflow::cx::v3::Webhook> UpdateWebhook(
      google::cloud::dialogflow::cx::v3::Webhook const& webhook,
      google::protobuf::FieldMask const& update_mask, Options opts = {});

  // clang-format off
  ///
  /// Updates the specified webhook.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.dialogflow.cx.v3.UpdateWebhookRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.dialogflow.cx.v3.Webhook])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.dialogflow.cx.v3.UpdateWebhookRequest]: @googleapis_reference_link{google/cloud/dialogflow/cx/v3/webhook.proto#L306}
  /// [google.cloud.dialogflow.cx.v3.Webhook]: @googleapis_reference_link{google/cloud/dialogflow/cx/v3/webhook.proto#L96}
  ///
  // clang-format on
  StatusOr<google::cloud::dialogflow::cx::v3::Webhook> UpdateWebhook(
      google::cloud::dialogflow::cx::v3::UpdateWebhookRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Deletes the specified webhook.
  ///
  /// @param name  Required. The name of the webhook to delete.
  ///  Format: `projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>/webhooks/<Webhook ID>`.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return a [`Status`] object. If the request failed, the
  ///     status contains the details of the failure.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.dialogflow.cx.v3.DeleteWebhookRequest]: @googleapis_reference_link{google/cloud/dialogflow/cx/v3/webhook.proto#L317}
  ///
  // clang-format on
  Status DeleteWebhook(std::string const& name, Options opts = {});

  // clang-format off
  ///
  /// Deletes the specified webhook.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.dialogflow.cx.v3.DeleteWebhookRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return a [`Status`] object. If the request failed, the
  ///     status contains the details of the failure.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.dialogflow.cx.v3.DeleteWebhookRequest]: @googleapis_reference_link{google/cloud/dialogflow/cx/v3/webhook.proto#L317}
  ///
  // clang-format on
  Status DeleteWebhook(
      google::cloud::dialogflow::cx::v3::DeleteWebhookRequest const& request,
      Options opts = {});

 private:
  std::shared_ptr<WebhooksConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_WEBHOOKS_CLIENT_H
