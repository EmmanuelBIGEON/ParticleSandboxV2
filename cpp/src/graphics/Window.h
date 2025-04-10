#pragma once

#ifdef USE_GLFW
#include <GLFW/glfw3.h>
#endif

namespace graphics {

    //! \class Window
    //! \brief Abstract class for a window
    class IWindow {
        public:
            virtual ~IWindow() = default;
            
            virtual bool Init() = 0;
            virtual bool Run() = 0;
            virtual bool Destroy() = 0;

            virtual void Display() = 0;
            virtual void Hide() = 0;
    };

#ifdef USE_GLFW // Collapse for clarity.
    //! \class GLFWWindow
    //! \brief GLFW Window implementation
    class GLFWWindow : public IWindow {
        public:
            GLFWWindow(int width, int height, const char* title); 
            virtual ~GLFWWindow();
            
            virtual bool Init() override;
            virtual bool Run() override;
            virtual bool Destroy() override;

            virtual void Display() override;
            virtual void Hide() override;

        protected:
            GLFWwindow* m_window;
    };
#endif

}