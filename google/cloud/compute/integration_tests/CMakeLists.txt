# ~~~
# Copyright 2023 Google LLC
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

# The tests require googletest to be installed. Force CMake to use the config
# file for googletest (that is, the CMake file installed by googletest itself),
# because the generic `FindGTest` module does not define the GTest::gmock
# target, and the target names are also weird.
find_package(GTest CONFIG REQUIRED)

set(compute_client_integration_tests # cmake-format: sort
                                     compute_integration_test.cc)

# Create a custom target so we can say "build all the tests"
add_custom_target(compute-client-integration-tests)

# Generate a target for each unit test.
foreach (fname ${compute_client_integration_tests})
    google_cloud_cpp_add_executable(target "compute" ${fname})
    target_link_libraries(
        ${target}
        PRIVATE google-cloud-cpp::experimental-compute google_cloud_cpp_testing
                GTest::gmock_main GTest::gmock GTest::gtest)
    google_cloud_cpp_add_common_options(${target})

    # With googletest it is relatively easy to exceed the default number of
    # sections (~65,000) in a single .obj file. Add the /bigobj option to all
    # the tests, even if it is not needed.
    if (MSVC)
        target_compile_options(${target} PRIVATE "/bigobj")
    endif ()
    add_test(NAME ${target} COMMAND ${target})
    set_tests_properties(${target}
                         PROPERTIES LABELS "integration-test;integration-test")
    add_dependencies(compute-client-integration-tests ${target})
endforeach ()
