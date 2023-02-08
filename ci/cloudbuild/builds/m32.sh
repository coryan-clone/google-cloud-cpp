#!/bin/bash
#
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

set -euo pipefail

source "$(dirname "$0")/../../lib/init.sh"
source module ci/lib/io.sh
source module ci/cloudbuild/builds/lib/cmake.sh
source module ci/cloudbuild/builds/lib/features.sh
source module ci/cloudbuild/builds/lib/integration.sh

export CC=gcc
export CXX=g++

mapfile -t cmake_args < <(cmake::common_args)
cmake_args+=(
  # This is the build to test with -m32, which requires a toolchain file.
  "--toolchain" "${PROJECT_ROOT}/ci/etc/m32-toolchain.cmake"
  # We should test all the GA libraries
  "-DGOOGLE_CLOUD_CPP_ENABLE=$(features::always_build_cmake),__ga_libraries__"
)

io::run cmake "${cmake_args[@]}"
# TODO(#10775) - have the script fail if the build has errors
cmake --build cmake-out -- -k 0 || true
mapfile -t ctest_args < <(ctest::common_args)
# TODO(#10775) - have the script fail if the unit tests have errors
env -C cmake-out ctest "${ctest_args[@]}" -LE "integration-test" || true

# TODO(#10775) - run the integration tests too
# integration::ctest_with_emulators "cmake-out" || true
