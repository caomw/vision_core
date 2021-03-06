# Copyright (c) 2016, Robert Lukierski.
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# 
# Redistributions of source code must retain the above copyright notice, this
# list of conditions and the following disclaimer.
# 
# Redistributions in binary form must reproduce the above copyright notice,
# this list of conditions and the following disclaimer in the documentation
# and/or other materials provided with the distribution.
# 
# Neither the name of the copyright holder nor the names of its
# contributors may be used to endorse or promote products derived from
# this software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
# ------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.1)

# ------------------------------------------------------------------------------
# Dependencies
# ------------------------------------------------------------------------------
# Google Test
find_package(GTest REQUIRED QUIET)
include_directories(${GTEST_INCLUDE_DIR})

include_directories(.)
include_directories(../tests)

# =========================================================================

set(TEST_SOURCES
../../tests/tests_main.cpp
#UT_CordSystems.cpp
#UT_DenavitHartenberg.cpp
#UT_Divergence.cpp
UT_Fitting.cpp
#UT_HammingDistance.cpp
#UT_Kalman.cpp
#UT_LeastSquares.cpp
#UT_LocalParamSE3.cpp
#UT_LossFunctions.cpp
#UT_PolarSpherical.cpp
#UT_Random.cpp
#UT_RANSAC.cpp
#UT_Statistics.cpp
#UT_TinySolver.cpp
)

add_executable(UT_VisionCore_Math ${TEST_SOURCES})
target_link_libraries(UT_VisionCore_Math ${GTEST_LIBRARY} ${PROJECT_NAME})
if(CUDA_FOUND)
    target_link_libraries(UT_VisionCore_Math ${CUDA_LIBRARIES})
endif()
if(OpenCL_FOUND)
    target_link_libraries(UT_VisionCore_Math ${OpenCL_LIBRARIES})
endif()
add_test(UT_VisionCore_Math UT_VisionCore_Math --gtest_output=xml:UT_VisionCore_Math.xml)
