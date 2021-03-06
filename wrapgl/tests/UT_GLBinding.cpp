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

#include <wrapgl/WrapGLBuffer.hpp>
#include <wrapgl/WrapGLTexture.hpp>
#include <wrapgl/WrapGLFramebuffer.hpp>
#include <wrapgl/WrapGLVertexArrayObject.hpp>
#include <wrapgl/WrapGLShader.hpp>
#include <wrapgl/WrapGLContext.hpp>
#include <wrapgl/WrapGLSampler.hpp>
#include <wrapgl/WrapGLQuery.hpp>
#include <wrapgl/WrapGLTransformFeedback.hpp>
#include <wrapgl/WrapGL.hpp>

class Test_GLBinding : public ::testing::Test
{
public:   
    Test_GLBinding()
    {
        
    }
    
    virtual ~Test_GLBinding()
    {
        
    }
};

TEST_F(Test_GLBinding, Dummy)
{
#if 0
    //wrapgl::FreeGLUTContext ctx("Test", 800, 600);
    wrapgl::X11Context ctx("Test", 800,600);
    
    while(!ctx.shouldQuit())
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        ctx.finishFrame();
    }
    
    ctx.shutdown();
#endif
}
