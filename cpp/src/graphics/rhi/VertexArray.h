#pragma once

#include <cstddef>

namespace graphics::rhi {

    enum class VertexAttribType {
        Float32,
        Int32
    };

    //! \class IVertexArray
    //! \brief An abstract class representing a vertex array.
    class IVertexArray {
        public:
            virtual ~IVertexArray() = default;

            //! \brief Bind the array.
            virtual void Bind() = 0;

            //! \brief Enable and fill attribute.
            virtual void SetAttribute(std::size_t index, int size, VertexAttribType type, 
                bool normalized, std::size_t stride, std::size_t offset) = 0;
    };

#ifdef USE_OPENGL
    #include <glad/glad.h>
    //! \class OpenGLVertexArray
    //! \brief An OpenGL vertex buffer
    class OpenGLVertexArray : public IVertexArray {
        public:
            OpenGLVertexArray();
            virtual ~OpenGLVertexArray() override;

            virtual void Bind() override;
            virtual void SetAttribute(std::size_t index, int size, VertexAttribType type, 
                bool normalized, std::size_t stride, std::size_t offset) override;
        private:
            unsigned int _internalVAO; // (VAO Vertex Array Object)

            static GLenum ToGLType(VertexAttribType type)
            {
                switch (type) {
                    case VertexAttribType::Float32: return GL_FLOAT;
                    case VertexAttribType::Int32:   return GL_INT;
                }
                return GL_FLOAT;
            }
    };
#endif
};