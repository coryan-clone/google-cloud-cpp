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

#include "google/cloud/bigquery/v2/minimal/internal/job_stats.h"
#include "google/cloud/bigquery/v2/minimal/internal/json_utils.h"
#include "google/cloud/internal/debug_string.h"

namespace google {
namespace cloud {
namespace bigquery_v2_minimal_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

EvaluationKind EvaluationKind::UnSpecified() {
  return EvaluationKind{"EVALUATION_KIND_UNSPECIFIED"};
}
EvaluationKind EvaluationKind::Statement() {
  return EvaluationKind{"STATEMENT"};
}
EvaluationKind EvaluationKind::Expression() {
  return EvaluationKind{"EXPRESSION"};
}

void to_json(nlohmann::json& j, JobStatistics const& s) {
  j = nlohmann::json{
      {"totalBytesProcessed", s.total_bytes_processed},
      {"numChildJobs", s.num_child_jobs},
      {"parentJobId", s.parent_job_id},
      {"sessionInfo", s.session_info},
      {"transactionInfo", s.transaction_info},
      {"reservation_id", s.reservation_id},
      {"rowLevelSecurityStatistics", s.row_level_security_statistics},
      {"dataMaskingStatistics", s.data_masking_statistics},
      {"completionRatio", s.completion_ratio},
      {"quotaDeferments", s.quota_deferments},
      {"scriptStatistics", s.script_statistics},
      {"query", s.job_query_stats}};

  ToJson(s.start_time, j, "startTime");
  ToJson(s.end_time, j, "endTime");
  ToJson(s.creation_time, j, "creationTime");
  ToJson(s.total_slot_time, j, "totalSlotMs");
  ToJson(s.final_execution_duration, j, "finalExecutionDurationMs");
}

void from_json(nlohmann::json const& j, JobStatistics& s) {
  if (j.contains("totalBytesProcessed")) {
    j.at("totalBytesProcessed").get_to(s.total_bytes_processed);
  }
  if (j.contains("numChildJobs")) j.at("numChildJobs").get_to(s.num_child_jobs);
  if (j.contains("parentJobId")) j.at("parentJobId").get_to(s.parent_job_id);
  if (j.contains("sessionInfo")) j.at("sessionInfo").get_to(s.session_info);
  if (j.contains("transactionInfo")) {
    j.at("transactionInfo").get_to(s.transaction_info);
  }
  if (j.contains("reservation_id")) {
    j.at("reservation_id").get_to(s.reservation_id);
  }
  if (j.contains("rowLevelSecurityStatistics")) {
    j.at("rowLevelSecurityStatistics").get_to(s.row_level_security_statistics);
  }
  if (j.contains("dataMaskingStatistics")) {
    j.at("dataMaskingStatistics").get_to(s.data_masking_statistics);
  }
  if (j.contains("completionRatio")) {
    j.at("completionRatio").get_to(s.completion_ratio);
  }
  if (j.contains("quotaDeferments")) {
    j.at("quotaDeferments").get_to(s.quota_deferments);
  }
  if (j.contains("scriptStatistics")) {
    j.at("scriptStatistics").get_to(s.script_statistics);
  }
  if (j.contains("query")) j.at("query").get_to(s.job_query_stats);

  FromJson(s.start_time, j, "startTime");
  FromJson(s.end_time, j, "endTime");
  FromJson(s.creation_time, j, "creationTime");
  FromJson(s.total_slot_time, j, "totalSlotMs");
  FromJson(s.final_execution_duration, j, "finalExecutionDurationMs");
}

bool operator==(ScriptStackFrame const& lhs, ScriptStackFrame const& rhs) {
  return lhs.end_column == rhs.end_column && lhs.end_line == rhs.end_line &&
         lhs.procedure_id == rhs.procedure_id &&
         lhs.start_column == rhs.start_column &&
         lhs.start_line == rhs.start_line && lhs.text == rhs.text;
}

bool operator==(ScriptStatistics const& lhs, ScriptStatistics const& rhs) {
  auto const eq = lhs.evaluation_kind == rhs.evaluation_kind;
  return eq && (std::equal(lhs.stack_frames.begin(), lhs.stack_frames.end(),
                           rhs.stack_frames.begin()));
}

std::string EvaluationKind::DebugString(absl::string_view name,
                                        TracingOptions const& options,
                                        int indent) const {
  return internal::DebugFormatter(name, options, indent)
      .StringField("value", value)
      .Build();
}

std::string ScriptStackFrame::DebugString(absl::string_view name,
                                          TracingOptions const& options,
                                          int indent) const {
  return internal::DebugFormatter(name, options, indent)
      .Field("start_line", start_line)
      .Field("start_column", start_column)
      .Field("end_line", end_line)
      .Field("end_column", end_column)
      .StringField("procedure_id", procedure_id)
      .StringField("text", text)
      .Build();
}

std::string ScriptStatistics::DebugString(absl::string_view name,
                                          TracingOptions const& options,
                                          int indent) const {
  return internal::DebugFormatter(name, options, indent)
      .Field("stack_frames", stack_frames)
      .SubMessage("evaluation_kind", evaluation_kind)
      .Build();
}

std::string JobStatistics::DebugString(absl::string_view name,
                                       TracingOptions const& options,
                                       int indent) const {
  return internal::DebugFormatter(name, options, indent)
      .Field("creation_time", creation_time)
      .Field("start_time", start_time)
      .Field("end_time", end_time)
      .Field("total_slot_time", total_slot_time)
      .Field("final_execution_duration", final_execution_duration)
      .Field("total_bytes_processed", total_bytes_processed)
      .Field("num_child_jobs", num_child_jobs)
      .Field("row_level_security_applied",
             row_level_security_statistics.row_level_security_applied)
      .Field("data_masking_applied",
             data_masking_statistics.data_masking_applied)
      .Field("completion_ratio", completion_ratio)
      .Field("quota_deferments", quota_deferments)
      .StringField("parent_job_id", parent_job_id)
      .StringField("session_id", session_info.session_id)
      .StringField("transaction_id", transaction_info.transaction_id)
      .StringField("reservation_id", reservation_id)
      .SubMessage("script_statistics", script_statistics)
      .SubMessage("job_query_stats", job_query_stats)
      .Build();
}

void to_json(nlohmann::json& j, ScriptStackFrame const& s) {
  j = nlohmann::json{
      {"startLine", s.start_line},     {"startColumn", s.start_column},
      {"endLine", s.end_line},         {"endColumn", s.end_column},
      {"procedureId", s.procedure_id}, {"text", s.text}};
}
void from_json(nlohmann::json const& j, ScriptStackFrame& s) {
  if (j.contains("startLine")) j.at("startLine").get_to(s.start_line);
  if (j.contains("startColumn")) j.at("startColumn").get_to(s.start_column);
  if (j.contains("endLine")) j.at("endLine").get_to(s.end_line);
  if (j.contains("endColumn")) j.at("endColumn").get_to(s.end_column);
  if (j.contains("procedureId")) j.at("procedureId").get_to(s.procedure_id);
  if (j.contains("text")) j.at("text").get_to(s.text);
}

void to_json(nlohmann::json& j, RowLevelSecurityStatistics const& r) {
  j = nlohmann::json{{"rowLevelSecurityApplied", r.row_level_security_applied}};
}
void from_json(nlohmann::json const& j, RowLevelSecurityStatistics& r) {
  if (j.contains("rowLevelSecurityApplied")) {
    j.at("rowLevelSecurityApplied").get_to(r.row_level_security_applied);
  }
}

void to_json(nlohmann::json& j, DataMaskingStatistics const& d) {
  j = nlohmann::json{{"dataMaskingApplied", d.data_masking_applied}};
}
void from_json(nlohmann::json const& j, DataMaskingStatistics& d) {
  if (j.contains("dataMaskingApplied")) {
    j.at("dataMaskingApplied").get_to(d.data_masking_applied);
  }
}

void to_json(nlohmann::json& j, TransactionInfo const& t) {
  j = nlohmann::json{{"transactionId", t.transaction_id}};
}
void from_json(nlohmann::json const& j, TransactionInfo& t) {
  if (j.contains("transactionId")) {
    j.at("transactionId").get_to(t.transaction_id);
  }
}

void to_json(nlohmann::json& j, ScriptStatistics const& s) {
  j = nlohmann::json{{"evaluationKind", s.evaluation_kind},
                     {"stackFrames", s.stack_frames}};
}
void from_json(nlohmann::json const& j, ScriptStatistics& s) {
  if (j.contains("evaluationKind")) {
    j.at("evaluationKind").get_to(s.evaluation_kind);
  }
  if (j.contains("stackFrames")) j.at("stackFrames").get_to(s.stack_frames);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_v2_minimal_internal
}  // namespace cloud
}  // namespace google
