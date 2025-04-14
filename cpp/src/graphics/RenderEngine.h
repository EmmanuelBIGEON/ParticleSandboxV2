#pragma once

#include <glm/ext.hpp>

namespace graphics {
    //! \class IRenderEngine
    //! \brief An abstract class representing a render engine.
    //! Interfacing with graphic APIs such as OpenGL, VUlkan, DirectX...
    class IRenderEngine {
        public:
            virtual ~IRenderEngine() = default;

            virtual void FillScreen(const glm::vec3& color) = 0;
    };

#ifdef USE_OPENGL
    //! \class OpenGLRenderDevice
    //! \brief An OpenGL RenderDevice.
    class OpenGLRenderEngine : public IRenderEngine {
        public:
            OpenGLRenderEngine();
            virtual ~OpenGLRenderEngine() override;

            void FillScreen(const glm::vec3& color) override;
    };
#endif
}