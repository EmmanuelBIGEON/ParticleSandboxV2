#pragma once

#include <memory>

#ifdef USE_GLFW
#include <GLFW/glfw3.h>
#endif

#include "Scene.h"
#include "Renderer.h"

namespace graphics {

    enum class WindowType { GLFW };

    //! \class Window
    //! \brief Abstract class for a window
    class IWindow {
        public:
            virtual ~IWindow() = default;
            
            virtual void SetScene(std::unique_ptr<IScene> scene) = 0;
            virtual void SetRenderer(std::unique_ptr<IRenderer> renderer) = 0;
            virtual bool Run() = 0;
    };

    //! \class WindowFactory
    class WindowFactory {
        public:
            static std::unique_ptr<IWindow> Create(WindowType type, int width, int height, const char* title);
    };
    

#ifdef USE_GLFW // Collapse for clarity.
    //! \class GLFWWindow
    //! \brief GLFW Window implementation
    class GLFWWindow : public IWindow {
        public:
            GLFWWindow(int width, int height, const char* title); 
            virtual ~GLFWWindow() override;
            
            virtual bool Run() override;
            virtual void SetScene(std::unique_ptr<IScene> scene) override;
            virtual void SetRenderer(std::unique_ptr<IRenderer> renderer) override;

        protected:
            GLFWwindow* _window;
            std::unique_ptr<IScene> _scene;
            std::unique_ptr<IRenderer> _renderer;
    };
#endif

}