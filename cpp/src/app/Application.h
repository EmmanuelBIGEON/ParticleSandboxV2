#pragma once

#include <memory>

#include "graphics/Window.h"
#include "graphics/RenderDevice.h"

namespace app {
    //! \class IApplication
    //! \brief Abstract class for an application
    class IApplication {
        public:
            virtual ~IApplication() = default;

            virtual bool Run() = 0;
    };

    class ParticleSandboxApplication : public IApplication {
        public:
            ParticleSandboxApplication();
            virtual ~ParticleSandboxApplication();

            virtual bool Run() override;
        
        protected:
            std::unique_ptr<graphics::IWindow> _mainWindow;
            std::unique_ptr<graphics::IRenderDevice> _renderDevice;
    };
}