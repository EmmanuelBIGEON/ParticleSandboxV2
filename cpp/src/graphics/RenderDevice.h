#pragma once

namespace graphics {
    //! \class IRenderDevice
    //! \brief An abstract class representing a render device.
    //! Interfacing with graphic APIs such as OpenGL, VUlkan, DirectX...
    class IRenderDevice {
        public:
            virtual ~IRenderDevice() = default;
    };

    //! \class OpenGLRenderDevice
    //! \brief An OpenGL RenderDevice.
    class OpenGLRenderDevice : public IRenderDevice {
        public:
            OpenGLRenderDevice();
            virtual ~OpenGLRenderDevice() override;


    };
}