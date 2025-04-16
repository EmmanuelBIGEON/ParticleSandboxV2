#include "VertexArray.h"

using namespace graphics::rhi;

#ifdef USE_OPENGL
#include <glad/glad.h>

OpenGLVertexArray::OpenGLVertexArray()
{
    glGenVertexArrays(1, &_internalVAO);
}

OpenGLVertexArray::~OpenGLVertexArray()
{
    if (_internalVAO) glDeleteVertexArrays(1, &_internalVAO);
}

void OpenGLVertexArray::Bind()
{
    glBindVertexArray(_internalVAO);
}

void OpenGLVertexArray::SetAttribute(std::size_t index, int size, VertexAttribType type, bool normalized, std::size_t stride, std::size_t offset)
{
    glEnableVertexAttribArray(static_cast<GLuint>(index));
    glVertexAttribPointer(
        static_cast<GLuint>(index),
        size,
        ToGLType(type),
        normalized ? GL_TRUE : GL_FALSE,
        static_cast<GLsizei>(stride),
        reinterpret_cast<const void*>(offset));
}
#endif