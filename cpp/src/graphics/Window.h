#pragma once

#include <memory>

#ifdef USE_GLFW
#include <GLFW/glfw3.h>
#endif

namespace graphics {

    enum class WindowType { GLFW };

    //! \class Window
    //! \brief Abstract class for a window
    class IWindow {
        public:
            virtual ~IWindow() = default;
            
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
            virtual ~GLFWWindow();
            
            virtual bool Run() override;

        protected:
            GLFWwindow* _window;
    };
#endif

}