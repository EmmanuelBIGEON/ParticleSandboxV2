#pragma once

#include <cstddef>

namespace graphics::rhi {

    enum class VertexBufferUsage {
        Static,
        Dynamic
    };

    //! \class IVertexBuffer
    //! \brief An abstract class representing a vertex buffer.
    class IVertexBuffer {
        public:
            virtual ~IVertexBuffer() = default;

            //! \brief Bind the buffer.
            virtual void Bind() = 0;

            //! \brief Fill buffer data. 
            //! NOTICE : Automatically bind the buffer for safety.
            virtual void SetData(const void* data, std::size_t size, VertexBufferUsage usage) = 0;
    };

#ifdef USE_OPENGL
    //! \class OpenGLVertexBuffer
    //! \brief An OpenGL vertex buffer
    class OpenGLVertexBuffer : public IVertexBuffer {
        public:
            OpenGLVertexBuffer();
            virtual ~OpenGLVertexBuffer() override;

            virtual void Bind() override;
            virtual void SetData(const void* data, std::size_t size, VertexBufferUsage usage) override;
        private:
            unsigned int _internalVBO; // (VBO Vertex Buffer Object)
    };
#endif
};