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
 * Texture Samplers.
 * ****************************************************************************
 */

#ifndef WRAPGL_SAMPLER_HPP
#define WRAPGL_SAMPLER_HPP

#include <wrapgl/WrapGLCommon.hpp>

/**
 * TODO:
 * 
 *  glSamplerParameter
 */

namespace wrapgl
{
    
class Sampler
{
public:    
    Sampler() : sid(0)
    {
        create(0);
    }
    
    Sampler(GLuint texu) : sid(0)
    {
        create(texu);
    }
    
    virtual ~Sampler()
    {
        destroy();
    }
    
    void create(GLuint texu)
    {
        destroy();
        
        glGenSamplers(1, &sid);
        texunit = texu;
    }
    
    void destroy()
    {
        if(sid != 0)
        {
            glDeleteSamplers(1, &sid);
            sid = 0;
        }
    }
    
    inline bool isValid() const { return sid != 0; }
    
    inline void bind() const
    {
        glBindSampler(texunit, sid);
    }
    
    inline void unbind() const
    {
        glBindSampler(texunit, 0);
    }
    
    template<typename T>
    inline T get(GLenum param)
    {
        T ret;
        glGetSamplerParameterfv(sid, param, &ret);
        return ret;
    }
    
    template<typename T>
    inline void set(GLenum param, T val)
    {
        glSamplerParameterf(sid, param, val);
    }
    
    inline GLuint id() const { return sid; }
private:
    GLuint sid;
    GLuint texunit;
};
    
}

#endif // WRAPGL_SAMPLER_HPP
