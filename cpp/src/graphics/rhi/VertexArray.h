#pragma once

namespace graphics::rhi {
    //! \class IVertexArray
    //! \brief An abstract class representing a vertex array.
    class IVertexArray {
        public:
            virtual ~IVertexArray() = default;

            virtual void Bind() = 0;
    };

#ifdef USE_OPENGL
    //! \class OpenGLVertexArray
    //! \brief An OpenGL vertex buffer
    class OpenGLVertexArray : public IVertexArray {
        public:
            OpenGLVertexArray();
            virtual ~OpenGLVertexArray() override;

            virtual void Bind() override;
    };
#endif
};