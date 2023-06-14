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
// source: google/cloud/bigquery/biglake/v1/metastore.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_BIGLAKE_V1_METASTORE_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_BIGLAKE_V1_METASTORE_CONNECTION_H

#include "google/cloud/bigquery/biglake/v1/internal/metastore_retry_traits.h"
#include "google/cloud/bigquery/biglake/v1/metastore_connection_idempotency_policy.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <google/cloud/bigquery/biglake/v1/metastore.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_biglake_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using MetastoreServiceRetryPolicy =
    ::google::cloud::internal::TraitBasedRetryPolicy<
        bigquery_biglake_v1_internal::MetastoreServiceRetryTraits>;

using MetastoreServiceLimitedTimeRetryPolicy =
    ::google::cloud::internal::LimitedTimeRetryPolicy<
        bigquery_biglake_v1_internal::MetastoreServiceRetryTraits>;

using MetastoreServiceLimitedErrorCountRetryPolicy =
    ::google::cloud::internal::LimitedErrorCountRetryPolicy<
        bigquery_biglake_v1_internal::MetastoreServiceRetryTraits>;

/**
 * The `MetastoreServiceConnection` object for `MetastoreServiceClient`.
 *
 * This interface defines virtual methods for each of the user-facing overload
 * sets in `MetastoreServiceClient`. This allows users to inject custom behavior
 * (e.g., with a Google Mock object) when writing tests that use objects of type
 * `MetastoreServiceClient`.
 *
 * To create a concrete instance, see `MakeMetastoreServiceConnection()`.
 *
 * For mocking, see `bigquery_biglake_v1_mocks::MockMetastoreServiceConnection`.
 */
class MetastoreServiceConnection {
 public:
  virtual ~MetastoreServiceConnection() = 0;

  virtual Options options() { return Options{}; }

  virtual StatusOr<google::cloud::bigquery::biglake::v1::Catalog> CreateCatalog(
      google::cloud::bigquery::biglake::v1::CreateCatalogRequest const&
          request);

  virtual StatusOr<google::cloud::bigquery::biglake::v1::Catalog> DeleteCatalog(
      google::cloud::bigquery::biglake::v1::DeleteCatalogRequest const&
          request);

  virtual StatusOr<google::cloud::bigquery::biglake::v1::Catalog> GetCatalog(
      google::cloud::bigquery::biglake::v1::GetCatalogRequest const& request);

  virtual StreamRange<google::cloud::bigquery::biglake::v1::Catalog>
  ListCatalogs(
      google::cloud::bigquery::biglake::v1::ListCatalogsRequest request);

  virtual StatusOr<google::cloud::bigquery::biglake::v1::Database>
  CreateDatabase(
      google::cloud::bigquery::biglake::v1::CreateDatabaseRequest const&
          request);

  virtual StatusOr<google::cloud::bigquery::biglake::v1::Database>
  DeleteDatabase(
      google::cloud::bigquery::biglake::v1::DeleteDatabaseRequest const&
          request);

  virtual StatusOr<google::cloud::bigquery::biglake::v1::Database>
  UpdateDatabase(
      google::cloud::bigquery::biglake::v1::UpdateDatabaseRequest const&
          request);

  virtual StatusOr<google::cloud::bigquery::biglake::v1::Database> GetDatabase(
      google::cloud::bigquery::biglake::v1::GetDatabaseRequest const& request);

  virtual StreamRange<google::cloud::bigquery::biglake::v1::Database>
  ListDatabases(
      google::cloud::bigquery::biglake::v1::ListDatabasesRequest request);

  virtual StatusOr<google::cloud::bigquery::biglake::v1::Table> CreateTable(
      google::cloud::bigquery::biglake::v1::CreateTableRequest const& request);

  virtual StatusOr<google::cloud::bigquery::biglake::v1::Table> DeleteTable(
      google::cloud::bigquery::biglake::v1::DeleteTableRequest const& request);

  virtual StatusOr<google::cloud::bigquery::biglake::v1::Table> UpdateTable(
      google::cloud::bigquery::biglake::v1::UpdateTableRequest const& request);

  virtual StatusOr<google::cloud::bigquery::biglake::v1::Table> RenameTable(
      google::cloud::bigquery::biglake::v1::RenameTableRequest const& request);

  virtual StatusOr<google::cloud::bigquery::biglake::v1::Table> GetTable(
      google::cloud::bigquery::biglake::v1::GetTableRequest const& request);

  virtual StreamRange<google::cloud::bigquery::biglake::v1::Table> ListTables(
      google::cloud::bigquery::biglake::v1::ListTablesRequest request);
};

/**
 * A factory function to construct an object of type
 * `MetastoreServiceConnection`.
 *
 * The returned connection object should not be used directly; instead it
 * should be passed as an argument to the constructor of MetastoreServiceClient.
 *
 * The optional @p options argument may be used to configure aspects of the
 * returned `MetastoreServiceConnection`. Expected options are any of the types
 * in the following option lists:
 *
 * - `google::cloud::CommonOptionList`
 * - `google::cloud::GrpcOptionList`
 * - `google::cloud::UnifiedCredentialsOptionList`
 * - `google::cloud::bigquery_biglake_v1::MetastoreServicePolicyOptionList`
 *
 * @note Unexpected options will be ignored. To log unexpected options instead,
 *     set `GOOGLE_CLOUD_CPP_ENABLE_CLOG=yes` in the environment.
 *
 * @param options (optional) Configure the `MetastoreServiceConnection` created
 * by this function.
 */
std::shared_ptr<MetastoreServiceConnection> MakeMetastoreServiceConnection(
    Options options = {});

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_biglake_v1
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_BIGLAKE_V1_METASTORE_CONNECTION_H
