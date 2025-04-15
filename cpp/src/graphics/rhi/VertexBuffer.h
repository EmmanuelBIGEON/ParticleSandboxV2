#pragma once

namespace graphics::rhi {
    //! \class IVertexBuffer
    //! \brief An abstract class representing a vertex buffer.
    class IVertexBuffer {
        public:
            virtual ~IVertexBuffer() = default;

            virtual void Bind() = 0;
    };

#ifdef USE_OPENGL
    //! \class OpenGLVertexBuffer
    //! \brief An OpenGL vertex buffer
    class OpenGLVertexBuffer : public IVertexBuffer {
        public:
            OpenGLVertexBuffer();
            virtual ~OpenGLVertexBuffer() override;

            virtual void Bind() override;
    };
#endif
};