/**
 * ****************************************************************************
 * Copyright (c) 2015, Robert Lukierski.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * 
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * 
 * Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * ****************************************************************************
 */
// system
#include <stdint.h>
#include <stddef.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <exception>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <valarray>
#include <functional>

// testing framework & libraries
#include <gtest/gtest.h>

// google logger
#include <glog/logging.h>

#include <Platform.hpp>

class Test_OpenCL : public ::testing::Test
{
public:   
    Test_OpenCL()
    {
        
    }
    
    virtual ~Test_OpenCL()
    {
        
    }
};

TEST_F(Test_OpenCL, DevicesContexts)
{    
    std::vector<cl::Platform> platforms;
    
    cl::Platform::get(&platforms);
    
    for(cl::Platform& plat : platforms)
    {
        LOG(INFO) << "Platform " << plat.getInfo<CL_PLATFORM_PROFILE>() << " / " << plat.getInfo<CL_PLATFORM_VERSION>() << " / " << plat.getInfo<CL_PLATFORM_NAME>() << " / " << plat.getInfo<CL_PLATFORM_VENDOR>() << " / " << plat.getInfo<CL_PLATFORM_EXTENSIONS>();
        
        std::vector<cl::Device> devs;
        plat.getDevices(CL_DEVICE_TYPE_ALL, &devs);
        
        for(cl::Device& dev : devs)
        {
            LOG(INFO) << "\tDevice: " << dev.getInfo<CL_DEVICE_VENDOR>() << " / " << dev.getInfo<CL_DEVICE_NAME>();
        }
    }
}