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
 * Debugging.
 * ****************************************************************************
 */

#include <wrapgl/WrapGLCommon.hpp>

void wrapgl::Debug::enable()
{
    glEnable(GL_DEBUG_OUTPUT);
}

void wrapgl::Debug::disable()
{
    glDisable(GL_DEBUG_OUTPUT);
}

#ifdef WRAPGL_HAVE_GLBINDING
extern "C" void openGLDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
#else // WRAPGL_HAVE_GLBINDING
extern "C" void openGLDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, GLvoid* userParam)
#endif // WRAPGL_HAVE_GLBINDING
{
    const wrapgl::Debug::CallbackT& fun = *(const wrapgl::Debug::CallbackT*)userParam;
    if(userParam != 0)
    {
        if(fun)
        {
            fun(source, type, id, severity, std::string(message, length-1));
        }
    }
}

void wrapgl::Debug::registerCallback(const CallbackT& fun)
{
    glDebugMessageCallback(&openGLDebugCallback, (const void*)&fun);
}

void wrapgl::Debug::insert(GLenum source, GLenum type, GLuint id, GLenum severity, const std::string& msg)
{
    glDebugMessageInsert(source, type, id, severity, -1, msg.c_str());
}
