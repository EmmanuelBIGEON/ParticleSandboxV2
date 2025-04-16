#include "VertexBuffer.h"

using namespace graphics::rhi;

#ifdef USE_OPENGL
#include <glad/glad.h>
OpenGLVertexBuffer::OpenGLVertexBuffer()
{
    glGenBuffers(1, &_internalVBO);
}

OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
    if(_internalVBO) glDeleteBuffers(1, &_internalVBO);
}

void OpenGLVertexBuffer::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, _internalVBO);
}

void OpenGLVertexBuffer::SetData(const void* data, std::size_t size, VertexBufferUsage usage)
{
    Bind();

    GLenum glUsage = GL_STATIC_DRAW;
    switch (usage)
    {
        case VertexBufferUsage::Static:  glUsage = GL_STATIC_DRAW; break;
        case VertexBufferUsage::Dynamic: glUsage = GL_DYNAMIC_DRAW; break;
    }

    glBufferData(GL_ARRAY_BUFFER, size, data, glUsage);
}
#endif