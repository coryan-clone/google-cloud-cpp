# ~~~
# Copyright 2021 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ~~~

include(GoogleapisConfig)
set(DOXYGEN_PROJECT_NAME "Cloud Tasks API C++ Client")
set(DOXYGEN_PROJECT_BRIEF "A C++ Client Library for the Cloud Tasks API")
set(DOXYGEN_PROJECT_NUMBER "${PROJECT_VERSION}")
set(DOXYGEN_EXCLUDE_SYMBOLS "internal")
set(DOXYGEN_EXAMPLE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/quickstart")

unset(mocks_globs)
unset(source_globs)
set(service_dirs "" "v2/")
foreach (dir IN LISTS service_dirs)
    string(REPLACE "/" "_" ns "${dir}")
    list(APPEND source_globs "${dir}*.h" "${dir}*.cc" "${dir}internal/*")
    list(APPEND mocks_globs "${dir}mocks/*.h")
    list(APPEND DOXYGEN_EXCLUDE_SYMBOLS "tasks_${ns}internal")
    if (NOT dir STREQUAL "")
        list(APPEND DOXYGEN_EXAMPLE_PATH
             "${CMAKE_CURRENT_SOURCE_DIR}/${dir}samples")
    endif ()
endforeach ()

include(GoogleCloudCppDoxygen)
google_cloud_cpp_doxygen_targets("tasks" DEPENDS cloud-docs
                                 google-cloud-cpp::tasks_protos)

include(GoogleCloudCppCommon)

include(CompileProtos)
google_cloud_cpp_find_proto_include_dir(PROTO_INCLUDE_DIR)
google_cloud_cpp_load_protolist(
    proto_list
    "${PROJECT_SOURCE_DIR}/external/googleapis/protolists/tasks.list")
google_cloud_cpp_load_protodeps(
    proto_deps "${PROJECT_SOURCE_DIR}/external/googleapis/protodeps/tasks.deps")
google_cloud_cpp_grpcpp_library(
    google_cloud_cpp_tasks_protos # cmake-format: sort
    ${proto_list} PROTO_PATH_DIRECTORIES "${EXTERNAL_GOOGLEAPIS_SOURCE}"
    "${PROTO_INCLUDE_DIR}")
external_googleapis_set_version_and_alias(tasks_protos)
target_link_libraries(google_cloud_cpp_tasks_protos PUBLIC ${proto_deps})

file(
    GLOB source_files
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    ${source_globs})
list(SORT source_files)
add_library(google_cloud_cpp_tasks ${source_files})
target_include_directories(
    google_cloud_cpp_tasks
    PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
           $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
           $<INSTALL_INTERFACE:include>)
target_link_libraries(
    google_cloud_cpp_tasks
    PUBLIC google-cloud-cpp::grpc_utils google-cloud-cpp::common
           google-cloud-cpp::tasks_protos)
google_cloud_cpp_add_common_options(google_cloud_cpp_tasks)
set_target_properties(
    google_cloud_cpp_tasks
    PROPERTIES EXPORT_NAME google-cloud-cpp::tasks
               VERSION "${PROJECT_VERSION}"
               SOVERSION "${PROJECT_VERSION_MAJOR}")
target_compile_options(google_cloud_cpp_tasks
                       PUBLIC ${GOOGLE_CLOUD_CPP_EXCEPTIONS_FLAG})

add_library(google-cloud-cpp::tasks ALIAS google_cloud_cpp_tasks)

# Create a header-only library for the mocks. We use a CMake `INTERFACE` library
# for these, a regular library would not work on macOS (where the library needs
# at least one .o file). Unfortunately INTERFACE libraries are a bit weird in
# that they need absolute paths for their sources.
file(
    GLOB relative_mock_files
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    ${mocks_globs})
list(SORT relative_mock_files)
set(mock_files)
foreach (file IN LISTS relative_mock_files)
    list(APPEND mock_files "${CMAKE_CURRENT_SOURCE_DIR}/${file}")
endforeach ()
add_library(google_cloud_cpp_tasks_mocks INTERFACE)
target_sources(google_cloud_cpp_tasks_mocks INTERFACE ${mock_files})
target_link_libraries(
    google_cloud_cpp_tasks_mocks
    INTERFACE google-cloud-cpp::tasks GTest::gmock_main GTest::gmock
              GTest::gtest)
set_target_properties(google_cloud_cpp_tasks_mocks
                      PROPERTIES EXPORT_NAME google-cloud-cpp::tasks_mocks)
target_include_directories(
    google_cloud_cpp_tasks_mocks
    INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
              $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
              $<INSTALL_INTERFACE:include>)
target_compile_options(google_cloud_cpp_tasks_mocks
                       INTERFACE ${GOOGLE_CLOUD_CPP_EXCEPTIONS_FLAG})

include(CTest)
if (BUILD_TESTING)
    add_executable(tasks_quickstart "quickstart/quickstart.cc")
    target_link_libraries(tasks_quickstart PRIVATE google-cloud-cpp::tasks)
    google_cloud_cpp_add_common_options(tasks_quickstart)
    add_test(
        NAME tasks_quickstart
        COMMAND
            cmake -P "${PROJECT_SOURCE_DIR}/cmake/quickstart-runner.cmake"
            $<TARGET_FILE:tasks_quickstart> GOOGLE_CLOUD_PROJECT
            GOOGLE_CLOUD_CPP_TEST_REGION)
    set_tests_properties(tasks_quickstart
                         PROPERTIES LABELS "integration-test;quickstart")
endif ()

# Get the destination directories based on the GNU recommendations.
include(GNUInstallDirs)

# Export the CMake targets to make it easy to create configuration files.
install(
    EXPORT google_cloud_cpp_tasks-targets
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/google_cloud_cpp_tasks"
    COMPONENT google_cloud_cpp_development)

# Install the libraries and headers in the locations determined by
# GNUInstallDirs
install(
    TARGETS google_cloud_cpp_tasks google_cloud_cpp_tasks_protos
    EXPORT google_cloud_cpp_tasks-targets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
            COMPONENT google_cloud_cpp_runtime
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            COMPONENT google_cloud_cpp_runtime
            NAMELINK_SKIP
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            COMPONENT google_cloud_cpp_development)
# With CMake-3.12 and higher we could avoid this separate command (and the
# duplication).
install(
    TARGETS google_cloud_cpp_tasks google_cloud_cpp_tasks_protos
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            COMPONENT google_cloud_cpp_development
            NAMELINK_ONLY
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            COMPONENT google_cloud_cpp_development)

google_cloud_cpp_install_proto_library_protos("google_cloud_cpp_tasks_protos"
                                              "${EXTERNAL_GOOGLEAPIS_SOURCE}")
google_cloud_cpp_install_proto_library_headers("google_cloud_cpp_tasks_protos")
google_cloud_cpp_install_headers("google_cloud_cpp_tasks"
                                 "include/google/cloud/tasks")
google_cloud_cpp_install_headers("google_cloud_cpp_tasks_mocks"
                                 "include/google/cloud/tasks")

google_cloud_cpp_add_pkgconfig(
    tasks
    "The Cloud Tasks API C++ Client Library"
    "Provides C++ APIs to use the Cloud Tasks API."
    "google_cloud_cpp_grpc_utils"
    "google_cloud_cpp_common"
    "google_cloud_cpp_tasks_protos")

# Create and install the CMake configuration files.
include(CMakePackageConfigHelpers)
configure_file("config.cmake.in" "google_cloud_cpp_tasks-config.cmake" @ONLY)
write_basic_package_version_file(
    "google_cloud_cpp_tasks-config-version.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY ExactVersion)

install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/google_cloud_cpp_tasks-config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/google_cloud_cpp_tasks-config-version.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/google_cloud_cpp_tasks"
    COMPONENT google_cloud_cpp_development)

external_googleapis_install_pc("google_cloud_cpp_tasks_protos")

# google-cloud-cpp::tasks must be defined before we can add the samples.
foreach (dir IN LISTS service_dirs)
    if (BUILD_TESTING AND GOOGLE_CLOUD_CPP_ENABLE_CXX_EXCEPTIONS)
        google_cloud_cpp_add_samples_relative("tasks" "${dir}samples/")
    endif ()
endforeach ()
