// Copyright 2017 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGTABLE_TABLE_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGTABLE_TABLE_H

#include "google/cloud/bigtable/completion_queue.h"
#include "google/cloud/bigtable/data_client.h"
#include "google/cloud/bigtable/data_connection.h"
#include "google/cloud/bigtable/filters.h"
#include "google/cloud/bigtable/idempotent_mutation_policy.h"
#include "google/cloud/bigtable/internal/defaults.h"
#include "google/cloud/bigtable/internal/legacy_async_row_reader.h"
#include "google/cloud/bigtable/mutation_branch.h"
#include "google/cloud/bigtable/mutations.h"
#include "google/cloud/bigtable/options.h"
#include "google/cloud/bigtable/read_modify_write_rule.h"
#include "google/cloud/bigtable/resource_names.h"
#include "google/cloud/bigtable/row_key_sample.h"
#include "google/cloud/bigtable/row_reader.h"
#include "google/cloud/bigtable/row_set.h"
#include "google/cloud/bigtable/rpc_backoff_policy.h"
#include "google/cloud/bigtable/rpc_retry_policy.h"
#include "google/cloud/bigtable/table_resource.h"
#include "google/cloud/bigtable/version.h"
#include "google/cloud/future.h"
#include "google/cloud/grpc_error_delegate.h"
#include "google/cloud/internal/group_options.h"
#include "google/cloud/options.h"
#include "google/cloud/status.h"
#include "google/cloud/status_or.h"
#include "absl/meta/type_traits.h"
#include <string>
#include <vector>

namespace google {
namespace cloud {
namespace bigtable {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class MutationBatcher;

/**
 * Return the full table name.
 *
 * The full table name is:
 *
 * `projects/<PROJECT_ID>/instances/<INSTANCE_ID>/tables/<table_id>`
 *
 * Where the project id and instance id come from the @p client parameter.
 */
inline std::string TableName(std::shared_ptr<DataClient> const& client,
                             std::string const& table_id) {
  return InstanceName(client) + "/tables/" + table_id;
}

/**
 * The main interface to interact with data in a Cloud Bigtable table.
 *
 * This class provides member functions to:
 * - read specific rows: `Table::ReadRow()`
 * - scan a ranges of rows: `Table::ReadRows()`
 * - update or create a single row: `Table::Apply()`
 * - update or modify multiple rows: `Table::BulkApply()`
 * - update a row based on previous values: `Table::CheckAndMutateRow()`
 * - to atomically append data and/or increment multiple values in a row:
 *   `Table::ReadModifyWriteRow()`
 * - to sample the row keys: `Table::SampleRows()`.
 *
 * The class deals with the most common transient failures, and retries the
 * underlying RPC calls subject to the policies configured by the application.
 * These policies are documented in `Table::Table()`.
 *
 * @par Thread-safety
 * Instances of this class created via copy-construction or copy-assignment
 * share the underlying pool of connections. Access to these copies via multiple
 * threads is guaranteed to work. Two threads operating concurrently on the same
 * instance of this class is not guaranteed to work.
 *
 * @par Cost
 * Creating a new object of type `Table` is comparable to creating a few objects
 * of type `std::string` or a few objects of type `std::shared_ptr<int>`. The
 * class represents a shallow handle to a remote object.
 *
 * @par Error Handling
 * This class uses `StatusOr<T>` to report errors. When an operation fails to
 * perform its work the returned `StatusOr<T>` contains the error details. If
 * the `ok()` member function in the `StatusOr<T>` returns `true` then it
 * contains the expected result. Operations that do not return a value simply
 * return a `google::cloud::Status` indicating success or the details of the
 * error Please consult the [`StatusOr<T>`
 * documentation](#google::cloud::StatusOr) for more details.
 *
 * @code
 * namespace cbt = google::cloud::bigtable;
 * cbt::Table = ...;
 * google::cloud::StatusOr<std::pair<bool, cbt::Row>> row = table.ReadRow(...);
 *
 * if (!row) {
 *   std::cerr << "Error reading row\n";
 *   return;
 * }
 *
 * // Use "row" as a smart pointer here, e.g.:
 * if (!row->first) {
 *   std::cout << "Contacting the server was successful, but the row does not"
 *             << " exist\n";
 *   return;
 * }
 * std::cout << "The row has " << row->second.cells().size() << " cells\n";
 * @endcode
 *
 * In addition, the @ref index "main page" contains examples using `StatusOr<T>`
 * to handle errors.
 *
 * @par Retry, Backoff, and Idempotency Policies
 * The library automatically retries requests that fail with transient errors,
 * and uses [truncated exponential backoff][backoff-link] to backoff between
 * retries. The default policies are to continue retrying for up to 10 minutes.
 * On each transient failure the backoff period is doubled, starting with an
 * initial backoff of 100 milliseconds. The backoff period growth is truncated
 * at 60 seconds. The default idempotency policy is to only retry idempotent
 * operations. Note that most operations that change state are **not**
 * idempotent.
 *
 * The application can override these policies when constructing objects of this
 * class. The documentation for the constructors show examples of this in
 * action.
 *
 * [backoff-link]: https://cloud.google.com/storage/docs/exponential-backoff
 *
 * @see https://cloud.google.com/bigtable/ for an overview of Cloud Bigtable.
 *
 * @see https://cloud.google.com/bigtable/docs/overview for an overview of the
 *     Cloud Bigtable data model.
 *
 * @see https://cloud.google.com/bigtable/docs/instances-clusters-nodes for an
 *     introduction of the main APIs into Cloud Bigtable.
 *
 * @see https://cloud.google.com/bigtable/docs/reference/service-apis-overview
 *     for an overview of the underlying Cloud Bigtable API.
 *
 * @see #google::cloud::StatusOr for a description of the error reporting class
 *     used by this library.
 *
 * @see `LimitedTimeRetryPolicy` and `LimitedErrorCountRetryPolicy` for
 *     alternative retry policies.
 *
 * @see `ExponentialBackoffPolicy` to configure different parameters for the
 *     exponential backoff policy.
 *
 * @see `SafeIdempotentMutationPolicy` and `AlwaysRetryMutationPolicy` for
 *     alternative idempotency policies.
 */
class Table {
 private:
  // We need to eliminate some function overloads from resolution, and that
  // requires a bit of infrastructure in the private section.

  /// A meta function to check if @p P is a valid Policy type.
  template <typename P>
  struct ValidPolicy
      : absl::disjunction<std::is_base_of<RPCBackoffPolicy, P>,
                          std::is_base_of<RPCRetryPolicy, P>,
                          std::is_base_of<IdempotentMutationPolicy, P>> {};

  /// A meta function to check if all the @p Policies are valid policy types.
  template <typename... Policies>
  struct ValidPolicies : absl::conjunction<ValidPolicy<Policies>...> {};

 public:
  /**
   * Constructs a `Table` object.
   *
   * @param conn the connection to the Cloud Bigtable service. See
   *     `MakeDataConnection()` for how to create a connection. To mock the
   *     behavior of `Table` in your tests, use a
   *     `bigtable_mocks::MockDataConnection`.
   * @param tr identifies the table resource by its project, instance, and table
   *     ids.
   * @param options Configuration options for the table. Use
   *     `AppProfileIdOption` to supply an app profile for the `Table`
   *     operations. Or configure retry / backoff / idempotency policies with
   *     the options enumerated in `DataPolicyOptionList`.
   *
   * @par Example Using AppProfile
   * @snippet bigtable_hello_app_profile.cc read with app profile
   *
   * @par Idempotency Policy Example
   * @snippet data_snippets.cc apply relaxed idempotency
   *
   * @par Modified Retry Policy Example
   * @snippet data_snippets.cc apply custom retry
   */
  explicit Table(std::shared_ptr<bigtable::DataConnection> conn,
                 TableResource tr, Options options = {})
      : table_(std::move(tr)),
        table_name_(table_.FullName()),
        connection_(std::move(conn)),
        options_(google::cloud::internal::MergeOptions(std::move(options),
                                                       connection_->options())),
        metadata_update_policy_(bigtable_internal::MakeMetadataUpdatePolicy(
            table_name_, app_profile_id())) {}

  std::string const& table_name() const { return table_name_; }
  std::string const& app_profile_id() const {
    return options_.get<AppProfileIdOption>();
  }
  std::string const& project_id() const {
    return table_.instance().project_id();
  }
  std::string const& instance_id() const {
    return table_.instance().instance_id();
  }
  std::string const& table_id() const { return table_.table_id(); }

  /**
   * Returns a Table that reuses the connection and configuration of this
   * Table, but with a different resource name.
   *
   * @note The app profile id is copied from this Table.
   */
  Table WithNewTarget(std::string project_id, std::string instance_id,
                      std::string table_id) const {
    auto table = *this;
    table.table_ = TableResource(std::move(project_id), std::move(instance_id),
                                 std::move(table_id));
    table.table_name_ = table.table_.FullName();
    table.metadata_update_policy_ = bigtable_internal::MakeMetadataUpdatePolicy(
        table.table_name_, table.app_profile_id());
    return table;
  }

  /**
   * Returns a Table that reuses the connection and configuration of this
   * Table, but with a different resource name.
   */
  Table WithNewTarget(std::string project_id, std::string instance_id,
                      std::string app_profile_id, std::string table_id) const {
    auto table = *this;
    table.table_ = TableResource(std::move(project_id), std::move(instance_id),
                                 std::move(table_id));
    table.table_name_ = table.table_.FullName();
    table.options_.set<AppProfileIdOption>(std::move(app_profile_id));
    table.metadata_update_policy_ = bigtable_internal::MakeMetadataUpdatePolicy(
        table.table_name_, table.app_profile_id());
    return table;
  }

  /**
   * Attempts to apply the mutation to a row.
   *
   * @param mut the mutation. Note that this function takes ownership (and
   *     then discards) the data in the mutation.  In general, a
   *     `SingleRowMutation` can be used to modify and/or delete multiple cells,
   *     across different columns and column families.
   * @param opts (Optional) Override the class-level options, such as retry,
   *     backoff, and idempotency policies.
   *
   * @return status of the operation.
   *
   * @par Idempotency
   * This operation is idempotent if the provided mutations are idempotent. Note
   * that `google::cloud::bigtable::SetCell()` without an explicit timestamp is
   * **not** an idempotent operation.
   *
   * @par Thread-safety
   * Two threads concurrently calling this member function on the same instance
   * of this class are **not** guaranteed to work.
   *
   * @par Example
   * @snippet data_snippets.cc apply
   */
  Status Apply(SingleRowMutation mut, Options opts = {});

  /**
   * Makes asynchronous attempts to apply the mutation to a row.
   *
   * @param mut the mutation. Note that this function takes ownership
   *     (and then discards) the data in the mutation.  In general, a
   *     `SingleRowMutation` can be used to modify and/or delete
   *     multiple cells, across different columns and column families.
   * @param opts (Optional) Override the class-level options, such as retry,
   *     backoff, and idempotency policies.
   *
   * @par Idempotency
   * This operation is idempotent if the provided mutations are idempotent. Note
   * that `google::cloud::bigtable::SetCell()` without an explicit timestamp is
   * **not** an idempotent operation.
   *
   * @par Example
   * @snippet data_async_snippets.cc async-apply
   */
  future<Status> AsyncApply(SingleRowMutation mut, Options opts = {});

  /**
   * Attempts to apply mutations to multiple rows.
   *
   * These mutations are applied in bulk, in a single `MutateRowsRequest` RPC.
   * Failures are handled on a per mutation basis. If the result of a mutation
   * is a permanent (non-retryable) error, or if a non-idempotent mutation fails
   * for any reason, the mutation will not be retried. Only idempotent mutations
   * that encounter transient (retryable) errors can be retried. These mutations
   * are collected and retried in bulk. This function will continue to retry any
   * remaining errors until this class's retry policy is exhausted.
   *
   * It is possible that some mutations may not be attempted at all. These
   * mutations are considered failing and will be returned.
   *
   * @note This function takes ownership (and then discards) the data in the
   *     mutation. In general, a `BulkMutation` can modify multiple rows, and
   *     the modifications for each row can change (or create) multiple cells,
   *     across different columns and column families.
   *
   * @param mut the mutations
   * @param opts (Optional) Override the class-level options, such as retry,
   *     backoff, and idempotency policies.
   * @returns a list of failed mutations
   *
   * @par Idempotency
   * This operation is idempotent if the provided mutations are idempotent. Note
   * that `google::cloud::bigtable::SetCell()` without an explicit timestamp is
   * **not** an idempotent operation.
   *
   * @par Thread-safety
   * Two threads concurrently calling this member function on the same instance
   * of this class are **not** guaranteed to work. Consider copying the object
   * and using different copies in each thread.
   *
   * @par Example
   * @snippet data_snippets.cc bulk apply
   */
  std::vector<FailedMutation> BulkApply(BulkMutation mut, Options opts = {});

  /**
   * Makes asynchronous attempts to apply mutations to multiple rows.
   *
   * These mutations are applied in bulk, in a single `MutateRowsRequest` RPC.
   * Failures are handled on a per mutation basis. If the result of a mutation
   * is a permanent (non-retryable) error, or if a non-idempotent mutation fails
   * for any reason, the mutation will not be retried. Only idempotent mutations
   * that encounter transient (retryable) errors can be retried. These mutations
   * are collected and retried in bulk. This function will continue to retry any
   * remaining errors until this class's retry policy is exhausted.
   *
   * It is possible that some mutations may not be attempted at all. These
   * mutations are considered failing and will be returned.
   *
   * @note This function takes ownership (and then discards) the data in the
   *     mutation. In general, a `BulkMutation` can modify multiple rows, and
   *     the modifications for each row can change (or create) multiple cells,
   *     across different columns and column families.
   *
   * @param mut the mutations
   * @param opts (Optional) Override the class-level options, such as retry,
   *     backoff, and idempotency policies.
   * @returns a future to be filled with a list of failed mutations, when the
   *     operation is complete.
   *
   * @par Idempotency
   * This operation is idempotent if the provided mutations are idempotent. Note
   * that `google::cloud::bigtable::SetCell()` without an explicit timestamp is
   * **not** an idempotent operation.
   *
   * @par Thread-safety
   * Two threads concurrently calling this member function on the same instance
   * of this class are **not** guaranteed to work. Consider copying the object
   * and using different copies in each thread.
   *
   * @par Example
   * @snippet data_async_snippets.cc bulk async-bulk-apply
   */
  future<std::vector<FailedMutation>> AsyncBulkApply(BulkMutation mut,
                                                     Options opts = {});

  /**
   * Reads a set of rows from the table.
   *
   * @param row_set the rows to read from.
   * @param filter is applied on the server-side to data in the rows.
   * @param opts (Optional) Override the class-level options, such as retry,
   *     backoff, and idempotency policies.
   *
   * @par Idempotency
   * This is a read-only operation and therefore it is always idempotent.
   *
   * @par Thread-safety
   * Two threads concurrently calling this member function on the same instance
   * of this class are **not** guaranteed to work. Consider copying the object
   * and using different copies in each thread.  The values returned by
   * different calls are independent with respect to thread-safety, please see
   * the `RowReader` documentation for more details.
   *
   * @par Example
   * @snippet read_snippets.cc read rows
   */
  RowReader ReadRows(RowSet row_set, Filter filter, Options opts = {});

  /**
   * Reads a limited set of rows from the table.
   *
   * @param row_set the rows to read from.
   * @param rows_limit the maximum number of rows to read. Cannot be a negative
   *     number or zero. Use `ReadRows(RowSet, Filter)` to read all matching
   *     rows.
   * @param filter is applied on the server-side to data in the rows.
   * @param opts (Optional) Override the class-level options, such as retry,
   *     backoff, and idempotency policies.
   *
   * @par Idempotency
   * This is a read-only operation and therefore it is always idempotent.
   *
   * @par Thread-safety
   * Two threads concurrently calling this member function on the same instance
   * of this class are **not** guaranteed to work. Consider copying the object
   * and using different copies in each thread.  The values returned by
   * different calls are independent with respect to thread-safety, please see
   * the `RowReader` documentation for more details.
   *
   * @par Example
   * @snippet read_snippets.cc read rows with limit
   */
  RowReader ReadRows(RowSet row_set, std::int64_t rows_limit, Filter filter,
                     Options opts = {});

  /**
   * Read and return a single row from the table.
   *
   * @param row_key the row to read.
   * @param filter a filter expression, can be used to select a subset of the
   *     column families and columns in the row.
   * @param opts (Optional) Override the class-level options, such as retry,
   *     backoff, and idempotency policies.
   * @returns a tuple, the first element is a boolean, with value `false` if the
   *     row does not exist.  If the first element is `true` the second element
   *     has the contents of the Row.  Note that the contents may be empty
   *     if the filter expression removes all column families and columns.
   *
   * @par Idempotency
   * This is a read-only operation and therefore it is always idempotent.
   *
   * @par Thread-safety
   * Two threads concurrently calling this member function on the same instance
   * of this class are **not** guaranteed to work. Consider copying the object
   * and using different copies in each thread.
   *
   * @par Example
   * @snippet read_snippets.cc read row
   */
  StatusOr<std::pair<bool, Row>> ReadRow(std::string row_key, Filter filter,
                                         Options opts = {});

  /**
   * Atomic test-and-set for a row using filter expressions.
   *
   * Atomically check the value of a row using a filter expression.  If the
   * expression passes (meaning at least one element is returned by it), one
   * set of mutations is applied.  If the filter does not pass, a different set
   * of mutations is applied.  The changes are atomically applied in the server.
   *
   * @param row_key the row to modify.
   * @param filter the filter expression.
   * @param true_mutations the mutations for the "filter passed" case.
   * @param false_mutations the mutations for the "filter did not pass" case.
   * @param opts (Optional) Override the class-level options, such as retry,
   *     backoff, and idempotency policies.
   * @returns true if the filter passed.
   *
   * @par Idempotency
   * This operation is always treated as non-idempotent.
   *
   * @par Thread-safety
   * Two threads concurrently calling this member function on the same instance
   * of this class are **not** guaranteed to work. Consider copying the object
   * and using different copies in each thread.
   *
   * @par Check for Value Example
   * @snippet data_snippets.cc check and mutate
   *
   * @par Check for Cell Presence Example
   * @snippet data_snippets.cc check and mutate not present
   */
  StatusOr<MutationBranch> CheckAndMutateRow(
      std::string row_key, Filter filter, std::vector<Mutation> true_mutations,
      std::vector<Mutation> false_mutations, Options opts = {});

  /**
   * Make an asynchronous request to conditionally mutate a row.
   *
   * @param row_key the row key on which the conditional mutation will be
   *     performed
   * @param filter the condition, depending on which the mutation will be
   *     performed
   * @param true_mutations the mutations which will be performed if @p filter is
   *     true
   * @param false_mutations the mutations which will be performed if @p filter
   *     is false
   * @param opts (Optional) Override the class-level options, such as retry,
   *     backoff, and idempotency policies.
   *
   * @par Idempotency
   * This operation is always treated as non-idempotent.
   *
   * @par Thread-safety
   * Two threads concurrently calling this member function on the same instance
   * of this class are **not** guaranteed to work. Consider copying the object
   * and using different copies in each thread.
   *
   * @par Example
   * @snippet data_async_snippets.cc async check and mutate
   */
  future<StatusOr<MutationBranch>> AsyncCheckAndMutateRow(
      std::string row_key, Filter filter, std::vector<Mutation> true_mutations,
      std::vector<Mutation> false_mutations, Options opts = {});

  /**
   * Sample of the row keys in the table, including approximate data sizes.
   *
   * @note The sample may only include one element for small tables.  In
   *     addition, the sample may include row keys that do not exist on the
   *     table, and may include the empty row key to indicate "end of table".
   *
   * @par Idempotency
   * This operation is always treated as idempotent.
   *
   * @par Thread-safety
   * Two threads concurrently calling this member function on the same instance
   * of this class are **not** guaranteed to work. Consider copying the object
   * and using different copies in each thread.
   *
   * @par Examples
   * @snippet data_snippets.cc sample row keys
   */
  StatusOr<std::vector<bigtable::RowKeySample>> SampleRows(Options opts = {});

  /**
   * Asynchronously obtains a sample of the row keys in the table, including
   * approximate data sizes.
   *
   * @returns a future, that becomes satisfied when the operation completes.
   *
   * @note The sample may only include one element for small tables. In
   *     addition, the sample may include row keys that do not exist on the
   *     table, and may include the empty row key to indicate "end of table".
   *
   * @par Idempotency
   * This operation is always treated as idempotent.
   *
   * @par Thread-safety
   * Two threads concurrently calling this member function on the same instance
   * of this class are **not** guaranteed to work. Consider copying the object
   * and using different copies in each thread.
   *
   * @par Examples
   * @snippet data_async_snippets.cc async sample row keys
   */
  future<StatusOr<std::vector<bigtable::RowKeySample>>> AsyncSampleRows(
      Options opts = {});

  /**
   * Atomically read and modify the row in the server, returning the
   * resulting row
   *
   * @tparam Args this is zero or more ReadModifyWriteRules to apply on a row.
   *     Options to override the class-level options, such as retry, backoff,
   *     and idempotency policies are also be passed via this parameter pack.
   * @param row_key the row to read
   * @param rule to modify the row. Two types of rules are applied here
   *     AppendValue which will read the existing value and append the
   *     text provided to the value.
   *     IncrementAmount which will read the existing uint64 big-endian-int
   *     and add the value provided.
   *     Both rules accept the family and column identifier to modify.
   * @param rules_and_options is the zero or more ReadModifyWriteRules to apply
   *     on a row. Options to override the class-level options, such as retry,
   *     backoff, and idempotency policies are also be passed via this parameter
   *     pack.
   * @returns the new contents of all modified cells.
   *
   * @par Idempotency
   * This operation is always treated as non-idempotent.
   *
   * @par Thread-safety
   * Two threads concurrently calling this member function on the same instance
   * of this class are **not** guaranteed to work. Consider copying the object
   * and using different copies in each thread.
   *
   * @par Example
   * @snippet data_snippets.cc read modify write
   */
  template <typename... Args>
  StatusOr<Row> ReadModifyWriteRow(std::string row_key,
                                   bigtable::ReadModifyWriteRule rule,
                                   Args&&... rules_and_options) {
    ::google::bigtable::v2::ReadModifyWriteRowRequest request;
    request.set_row_key(std::move(row_key));

    // Generate a better compile time error message than the default one
    // if the types do not match
    static_assert(
        absl::conjunction<absl::disjunction<
            std::is_convertible<Args, bigtable::ReadModifyWriteRule>,
            std::is_same<typename std::decay<Args>::type, Options>>...>::value,
        "The arguments passed to ReadModifyWriteRow(row_key,...) must be "
        "convertible to bigtable::ReadModifyWriteRule, or of type "
        "google::cloud::Options");

    *request.add_rules() = std::move(rule).as_proto();
    AddRules(request, std::forward<Args>(rules_and_options)...);
    auto opts = google::cloud::internal::GroupOptions(
        std::forward<Args>(rules_and_options)...);
    return ReadModifyWriteRowImpl(std::move(request), std::move(opts));
  }

  /**
   * Make an asynchronous request to atomically read and modify a row.
   *
   * @tparam Args this is zero or more ReadModifyWriteRules to apply on a row.
   *     Options to override the class-level options, such as retry, backoff,
   *     and idempotency policies are also be passed via this parameter pack.
   * @param row_key the row key on which modification will be performed
   * @param rule to modify the row. Two types of rules are applied here
   *     AppendValue which will read the existing value and append the
   *     text provided to the value.
   *     IncrementAmount which will read the existing uint64 big-endian-int
   *     and add the value provided.
   *     Both rules accept the family and column identifier to modify.
   * @param rules_and_options is the zero or more ReadModifyWriteRules to apply
   *     on a row. Options to override the class-level options, such as retry,
   *     backoff, and idempotency policies are also be passed via this parameter
   *     pack.
   * @returns a future, that becomes satisfied when the operation completes,
   *     at that point the future has the contents of all modified cells.
   *
   * @par Idempotency
   * This operation is always treated as non-idempotent.
   *
   * @par Thread-safety
   * Two threads concurrently calling this member function on the same instance
   * of this class are **not** guaranteed to work.
   *
   * @par Example
   * @snippet data_async_snippets.cc async read modify write
   */
  template <typename... Args>
  future<StatusOr<Row>> AsyncReadModifyWriteRow(
      std::string row_key, bigtable::ReadModifyWriteRule rule,
      Args&&... rules_and_options) {
    ::google::bigtable::v2::ReadModifyWriteRowRequest request;
    request.set_row_key(std::move(row_key));

    // Generate a better compile time error message than the default one
    // if the types do not match
    static_assert(
        absl::conjunction<absl::disjunction<
            std::is_convertible<Args, bigtable::ReadModifyWriteRule>,
            std::is_same<typename std::decay<Args>::type, Options>>...>::value,
        "The arguments passed to AsyncReadModifyWriteRow(row_key,...) must be "
        "convertible to bigtable::ReadModifyWriteRule, or of type "
        "google::cloud::Options");

    *request.add_rules() = std::move(rule).as_proto();
    AddRules(request, std::forward<Args>(rules_and_options)...);
    auto opts = google::cloud::internal::GroupOptions(
        std::forward<Args>(rules_and_options)...);
    return AsyncReadModifyWriteRowImpl(std::move(request), std::move(opts));
  }

  /**
   * Asynchronously reads a set of rows from the table.
   *
   * @param on_row the callback to be invoked on each successfully read row; it
   *     should be invocable with `Row` and return a future<bool>; the returned
   *     `future<bool>` should be satisfied with `true` when the user is ready
   *     to receive the next callback and with `false` when the user doesn't
   *     want any more rows; if `on_row` throws, the results are undefined
   * @param on_finish the callback to be invoked when the stream is closed; it
   *     should be invocable with `Status` and not return anything; it will
   *     always be called as the last callback; if `on_finish` throws, the
   *     results are undefined
   * @param row_set the rows to read from.
   * @param filter is applied on the server-side to data in the rows.
   * @param opts (Optional) Override the class-level options, such as retry,
   *     backoff, and idempotency policies.
   *
   * @tparam RowFunctor the type of the @p on_row callback.
   * @tparam FinishFunctor the type of the @p on_finish callback.
   *
   * @par Thread-safety
   * Two threads concurrently calling this member function on the same instance
   * of this class are **not** guaranteed to work. Consider copying the object
   * and using different copies in each thread.
   *
   * @par Example
   * @snippet data_async_snippets.cc async read rows
   */
  template <typename RowFunctor, typename FinishFunctor>
  void AsyncReadRows(RowFunctor on_row, FinishFunctor on_finish, RowSet row_set,
                     Filter filter, Options opts = {}) {
    AsyncReadRows(std::move(on_row), std::move(on_finish), std::move(row_set),
                  RowReader::NO_ROWS_LIMIT, std::move(filter), std::move(opts));
  }

  /**
   * Asynchronously reads a set of rows from the table.
   *
   * @param on_row the callback to be invoked on each successfully read row; it
   *     should be invocable with `Row` and return a future<bool>; the returned
   *     `future<bool>` should be satisfied with `true` when the user is ready
   *     to receive the next callback and with `false` when the user doesn't
   *     want any more rows; if `on_row` throws, the results are undefined
   * @param on_finish the callback to be invoked when the stream is closed; it
   *     should be invocable with `Status` and not return anything; it will
   *     always be called as the last callback; if `on_finish` throws, the
   *     results are undefined
   * @param row_set the rows to read from.
   * @param rows_limit the maximum number of rows to read. Cannot be a negative
   *     number or zero. Use `AsyncReadRows(RowSet, Filter)` to
   *     read all matching rows.
   * @param filter is applied on the server-side to data in the rows.
   * @param opts (Optional) Override the class-level options, such as retry,
   *     backoff, and idempotency policies.
   *
   * @tparam RowFunctor the type of the @p on_row callback.
   * @tparam FinishFunctor the type of the @p on_finish callback.
   *
   * @par Thread-safety
   * Two threads concurrently calling this member function on the same instance
   * of this class are **not** guaranteed to work. Consider copying the object
   * and using different copies in each thread. The callbacks passed to this
   * function may be executed on any thread running the provided completion
   * queue.
   *
   * @par Example
   * @snippet data_async_snippets.cc async read rows with limit
   */
  template <typename RowFunctor, typename FinishFunctor>
  void AsyncReadRows(RowFunctor on_row, FinishFunctor on_finish,
                     // NOLINTNEXTLINE(performance-unnecessary-value-param)
                     RowSet row_set, std::int64_t rows_limit, Filter filter,
                     Options opts = {}) {
    static_assert(
        google::cloud::internal::is_invocable<RowFunctor, bigtable::Row>::value,
        "RowFunctor must be invocable with Row.");
    static_assert(
        google::cloud::internal::is_invocable<FinishFunctor, Status>::value,
        "FinishFunctor must be invocable with Status.");
    static_assert(
        std::is_same<
            google::cloud::internal::invoke_result_t<RowFunctor, bigtable::Row>,
            future<bool>>::value,
        "RowFunctor should return a future<bool>.");

    auto on_row_ptr = std::make_shared<RowFunctor>(std::move(on_row));
    // NOLINTNEXTLINE(performance-unnecessary-value-param)
    auto on_row_fn = [on_row_ptr](Row row) {
      return (*on_row_ptr)(std::move(row));
    };

    auto on_finish_ptr = std::make_shared<FinishFunctor>(std::move(on_finish));
    // NOLINTNEXTLINE(performance-unnecessary-value-param)
    auto on_finish_fn = [on_finish_ptr](Status status) {
      return (*on_finish_ptr)(std::move(status));
    };

    if (connection_) {
      google::cloud::internal::OptionsSpan span(
          google::cloud::internal::MergeOptions(std::move(opts), options_));
      connection_->AsyncReadRows(table_name_, std::move(on_row_fn),
                                 std::move(on_finish_fn), std::move(row_set),
                                 rows_limit, std::move(filter));
      return;
    }
    if (!google::cloud::internal::IsEmpty(opts)) {
      on_finish_fn(
          Status(StatusCode::kInvalidArgument,
                 "Per-operation options only apply to `Table`s constructed "
                 "with a `DataConnection`."));
      return;
    }

    bigtable_internal::LegacyAsyncRowReader::Create(
        background_threads_->cq(), client_, app_profile_id(), table_name_,
        std::move(on_row_fn), std::move(on_finish_fn), std::move(row_set),
        rows_limit, std::move(filter), clone_rpc_retry_policy(),
        clone_rpc_backoff_policy(), metadata_update_policy_,
        std::make_unique<bigtable::internal::ReadRowsParserFactory>());
  }

  /**
   * Asynchronously read and return a single row from the table.
   *
   * @param row_key the row to read.
   * @param filter a filter expression, can be used to select a subset of the
   *     column families and columns in the row.
   * @param opts (Optional) Override the class-level options, such as retry,
   *     backoff, and idempotency policies.
   * @returns a future satisfied when the operation completes, fails
   *     permanently or keeps failing transiently, but the retry policy has been
   *     exhausted. The future will return a tuple. The first element is a
   *     boolean, with value `false` if the row does not exist.  If the first
   *     element is `true` the second element has the contents of the Row.  Note
   *     that the contents may be empty if the filter expression removes all
   *     column families and columns.
   *
   * @par Idempotency
   * This is a read-only operation and therefore it is always idempotent.
   *
   * @par Thread-safety
   * Two threads concurrently calling this member function on the same instance
   * of this class are **not** guaranteed to work. Consider copying the object
   * and using different copies in each thread.
   *
   * @par Example
   * @snippet data_async_snippets.cc async read row
   */
  future<StatusOr<std::pair<bool, Row>>> AsyncReadRow(std::string row_key,
                                                      Filter filter,
                                                      Options opts = {});

  /**
   * Constructor with default policies.
   *
   * @param client how to communicate with Cloud Bigtable, including
   *     credentials, the project id, and the instance id.
   * @param table_id the table id within the instance defined by client.  The
   *     full table name is `client->instance_name() + "/tables/" + table_id`.
   *
   * @deprecated #google::cloud::bigtable::DataConnection is the preferred way
   *     to communicate with the Bigtable Data API. To migrate existing code,
   *     see @ref migrating-from-dataclient "Migrating from DataClient".
   */
  Table(std::shared_ptr<DataClient> client, std::string const& table_id)
      : Table(std::move(client), std::string{}, table_id) {}

  /**
   * Constructor with default policies.
   *
   * @param client how to communicate with Cloud Bigtable, including
   *     credentials, the project id, and the instance id.
   * @param app_profile_id the app_profile_id needed for using the replication
   * API.
   * @param table_id the table id within the instance defined by client.  The
   *     full table name is `client->instance_name() + "/tables/" + table_id`.
   *
   * @deprecated #google::cloud::bigtable::DataConnection is the preferred way
   *     to communicate with the Bigtable Data API. To migrate existing code,
   *     see @ref migrating-from-dataclient "Migrating from DataClient".
   */
  Table(std::shared_ptr<DataClient> client, std::string app_profile_id,
        std::string const& table_id)
      : client_(std::move(client)),
        table_(client_->project_id(), client_->instance_id(), table_id),
        table_name_(table_.FullName()),
        rpc_retry_policy_prototype_(
            bigtable::DefaultRPCRetryPolicy(internal::kBigtableLimits)),
        rpc_backoff_policy_prototype_(
            bigtable::DefaultRPCBackoffPolicy(internal::kBigtableLimits)),
        idempotent_mutation_policy_(
            bigtable::DefaultIdempotentMutationPolicy()),
        background_threads_(client_->BackgroundThreadsFactory()()),
        options_(Options{}.set<AppProfileIdOption>(std::move(app_profile_id))),
        metadata_update_policy_(bigtable_internal::MakeMetadataUpdatePolicy(
            table_name_, this->app_profile_id())) {}

  /**
   * Constructor with explicit policies.
   *
   * The policies are passed by value, because this makes it easy for
   * applications to create them.
   *
   * @par Example
   * @code
   * using namespace std::chrono_literals; // assuming C++14.
   * auto client = bigtable::MakeClient(...); // details omitted
   * bigtable::Table table(client, "my-table",
   *                       // Allow up to 20 minutes to retry operations
   *                       bigtable::LimitedTimeRetryPolicy(20min),
   *                       // Start with 50 milliseconds backoff, grow
   *                       // exponentially to 5 minutes.
   *                       bigtable::ExponentialBackoffPolicy(50ms, 5min),
   *                       // Only retry idempotent mutations.
   *                       bigtable::SafeIdempotentMutationPolicy());
   * @endcode
   *
   * @param client how to communicate with Cloud Bigtable, including
   *     credentials, the project id, and the instance id.
   * @param table_id the table id within the instance defined by client.  The
   *     full table name is `client->instance_name() + "/tables/" + table_id`.
   * @param policies the set of policy overrides for this object.
   * @tparam Policies the types of the policies to override, the types must
   *     derive from one of the following types:
   *
   *     - `IdempotentMutationPolicy` which mutations are retried. Use
   *       `SafeIdempotentMutationPolicy` to only retry idempotent operations,
   *       use `AlwaysRetryMutationPolicy` to retry all operations. Read the
   *       caveats in the class definition to understand the downsides of the
   *       latter. You can also create your own policies that decide which
   *       mutations to retry.
   *     - `RPCBackoffPolicy` how to backoff from a failed RPC. Currently only
   *       `ExponentialBackoffPolicy` is implemented. You can also create your
   *       own policies that backoff using a different algorithm.
   *     - `RPCRetryPolicy` for how long to retry failed RPCs. Use
   *       `LimitedErrorCountRetryPolicy` to limit the number of failures
   *       allowed. Use `LimitedTimeRetryPolicy` to bound the time for any
   *       request. You can also create your own policies that combine time and
   *       error counts.
   *
   * @see SafeIdempotentMutationPolicy, AlwaysRetryMutationPolicy,
   *     ExponentialBackoffPolicy, LimitedErrorCountRetryPolicy,
   *     LimitedTimeRetryPolicy.
   *
   * @deprecated #google::cloud::bigtable::DataConnection is the preferred way
   *     to communicate with the Bigtable Data API. To migrate existing code,
   *     see @ref migrating-from-dataclient "Migrating from DataClient".
   */
  template <
      typename... Policies,
      /// @cond implementation_details
      typename std::enable_if<ValidPolicies<Policies...>::value, int>::type = 0
      /// @endcond
      >
  Table(std::shared_ptr<DataClient> client, std::string const& table_id,
        Policies&&... policies)
      : Table(std::move(client), table_id) {
    ChangePolicies(std::forward<Policies>(policies)...);
  }

  /**
   * Constructor with explicit policies.
   *
   * The policies are passed by value, because this makes it easy for
   * applications to create them.
   *
   * @par Example
   * @code
   * using namespace std::chrono_literals; // assuming C++14.
   * auto client = bigtable::MakeClient(...); // details omitted
   * bigtable::Table table(client, "app_id", "my-table",
   *                       // Allow up to 20 minutes to retry operations
   *                       bigtable::LimitedTimeRetryPolicy(20min),
   *                       // Start with 50 milliseconds backoff, grow
   *                       // exponentially to 5 minutes.
   *                       bigtable::ExponentialBackoffPolicy(50ms, 5min),
   *                       // Only retry idempotent mutations.
   *                       bigtable::SafeIdempotentMutationPolicy());
   * @endcode
   *
   * @param client how to communicate with Cloud Bigtable, including
   *     credentials, the project id, and the instance id.
   * @param app_profile_id the app_profile_id needed for using the replication
   * API.
   * @param table_id the table id within the instance defined by client.  The
   *     full table name is `client->instance_name() + "/tables/" + table_id`.
   * @param policies the set of policy overrides for this object.
   * @tparam Policies the types of the policies to override, the types must
   *     derive from one of the following types:
   *     - `IdempotentMutationPolicy` which mutations are retried. Use
   *       `SafeIdempotentMutationPolicy` to only retry idempotent operations,
   *       use `AlwaysRetryMutationPolicy` to retry all operations. Read the
   *       caveats in the class definition to understand the downsides of the
   *       latter. You can also create your own policies that decide which
   *       mutations to retry.
   *     - `RPCBackoffPolicy` how to backoff from a failed RPC. Currently only
   *       `ExponentialBackoffPolicy` is implemented. You can also create your
   *       own policies that backoff using a different algorithm.
   *     - `RPCRetryPolicy` for how long to retry failed RPCs. Use
   *       `LimitedErrorCountRetryPolicy` to limit the number of failures
   *       allowed. Use `LimitedTimeRetryPolicy` to bound the time for any
   *       request. You can also create your own policies that combine time and
   *       error counts.
   *
   * @see SafeIdempotentMutationPolicy, AlwaysRetryMutationPolicy,
   *     ExponentialBackoffPolicy, LimitedErrorCountRetryPolicy,
   *     LimitedTimeRetryPolicy.
   *
   * @deprecated #google::cloud::bigtable::DataConnection is the preferred way
   *     to communicate with the Bigtable Data API. To migrate existing code,
   *     see @ref migrating-from-dataclient "Migrating from DataClient".
   */
  template <
      typename... Policies,
      /// @cond implementation_details
      typename std::enable_if<ValidPolicies<Policies...>::value, int>::type = 0
      /// @endcond
      >
  Table(std::shared_ptr<DataClient> client, std::string app_profile_id,
        std::string const& table_id, Policies&&... policies)
      : Table(std::move(client), std::move(app_profile_id), table_id) {
    ChangePolicies(std::forward<Policies>(policies)...);
  }

 private:
  /**
   * Send request ReadModifyWriteRowRequest to modify the row and get it back
   */
  StatusOr<Row> ReadModifyWriteRowImpl(
      ::google::bigtable::v2::ReadModifyWriteRowRequest request, Options opts);

  future<StatusOr<Row>> AsyncReadModifyWriteRowImpl(
      ::google::bigtable::v2::ReadModifyWriteRowRequest request, Options opts);

  void AddRules(google::bigtable::v2::ReadModifyWriteRowRequest&) {
    // no-op for empty list
  }

  template <typename... Args>
  void AddRules(google::bigtable::v2::ReadModifyWriteRowRequest& request,
                bigtable::ReadModifyWriteRule rule, Args&&... args) {
    *request.add_rules() = std::move(rule).as_proto();
    AddRules(request, std::forward<Args>(args)...);
  }

  template <typename... Args>
  void AddRules(google::bigtable::v2::ReadModifyWriteRowRequest& request,
                Options const&, Args&&... args) {
    AddRules(request, std::forward<Args>(args)...);
  }

  std::unique_ptr<RPCRetryPolicy> clone_rpc_retry_policy() {
    return rpc_retry_policy_prototype_->clone();
  }

  std::unique_ptr<RPCBackoffPolicy> clone_rpc_backoff_policy() {
    return rpc_backoff_policy_prototype_->clone();
  }

  MetadataUpdatePolicy clone_metadata_update_policy() {
    return metadata_update_policy_;
  }

  std::unique_ptr<IdempotentMutationPolicy> clone_idempotent_mutation_policy() {
    return idempotent_mutation_policy_->clone();
  }

  ///@{
  /// @name Helper functions to implement constructors with changed policies.
  void ChangePolicy(RPCRetryPolicy const& policy) {
    rpc_retry_policy_prototype_ = policy.clone();
  }

  void ChangePolicy(RPCBackoffPolicy const& policy) {
    rpc_backoff_policy_prototype_ = policy.clone();
  }

  void ChangePolicy(IdempotentMutationPolicy const& policy) {
    idempotent_mutation_policy_ = policy.clone();
  }

  template <typename Policy, typename... Policies>
  void ChangePolicies(Policy&& policy, Policies&&... policies) {
    ChangePolicy(policy);
    ChangePolicies(std::forward<Policies>(policies)...);
  }
  void ChangePolicies() {}
  ///@}

  friend class MutationBatcher;
  std::shared_ptr<DataClient> client_;
  TableResource table_;
  std::string table_name_;
  std::shared_ptr<RPCRetryPolicy const> rpc_retry_policy_prototype_;
  std::shared_ptr<RPCBackoffPolicy const> rpc_backoff_policy_prototype_;
  std::shared_ptr<IdempotentMutationPolicy> idempotent_mutation_policy_;
  std::shared_ptr<BackgroundThreads> background_threads_;
  std::shared_ptr<DataConnection> connection_;
  Options options_;
  MetadataUpdatePolicy metadata_update_policy_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigtable
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGTABLE_TABLE_H
