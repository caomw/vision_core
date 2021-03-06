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
UT_Buffer1D.cpp
UT_Buffer2D.cpp
UT_Buffer3D.cpp
UT_Pyramid.cpp
UT_Reduction2D.cpp
)

set(TEST_KERNEL_SOURCES
UT_CUDABuffer1D.cu
UT_CUDABuffer2D.cu
UT_CUDABuffer3D.cu
UT_CUDAPyramid.cu
UT_CUDAReduction2D.cu
)

set(TEST_KERNEL_OBJS)
if(CUDA_FOUND)
    # We have to do this for CUDA_COMPILE!
    get_target_property(VisionCore_INT_INCLUDE_DIRS VisionCore INTERFACE_INCLUDE_DIRECTORIES)
    get_target_property(VisionCore_DEFINITIONS VisionCore INTERFACE_COMPILE_DEFINITIONS)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} APPEND PROPERTY INCLUDE_DIRECTORIES ${VisionCore_INT_INCLUDE_DIRS})
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} APPEND PROPERTY COMPILE_DEFINITIONS ${VisionCore_DEFINITIONS})
    cuda_compile(TEST_KERNEL_OBJS ${TEST_KERNEL_SOURCES} SHARED)
endif()

if(OpenCL_FOUND)
    list(APPEND TEST_SOURCES
    UT_OpenCLBuffer1D.cpp
    UT_OpenCLBuffer2D.cpp
    UT_OpenCLBuffer3D.cpp
    UT_OpenCLImage2D.cpp
    UT_OpenCLPyramid.cpp
    )
endif()

add_executable(UT_VisionCore_Buffers ${TEST_SOURCES} ${TEST_KERNEL_OBJS})
target_link_libraries(UT_VisionCore_Buffers ${GTEST_LIBRARY} ${PROJECT_NAME})
if(CUDA_FOUND)
    target_link_libraries(UT_VisionCore_Buffers ${CUDA_LIBRARIES})
endif()
if(OpenCL_FOUND)
    target_link_libraries(UT_VisionCore_Buffers ${OpenCL_LIBRARIES})
endif()
add_test(UT_VisionCore_Buffers UT_VisionCore_Buffers --gtest_output=xml:UT_VisionCore_Buffers.xml)
