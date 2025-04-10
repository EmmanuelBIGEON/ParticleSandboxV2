#include "Window.h"

#include <stdexcept>

using namespace graphics;

std::unique_ptr<IWindow> WindowFactory::Create(WindowType type, int width, int height, const char* title) {
    switch(type) {
#ifdef USE_GLFW
        case WindowType::GLFW:
            return std::make_unique<GLFWWindow>(width, height, title);
#endif
        default:
            throw std::runtime_error("Unsupported WindowType");
    }
}

#ifdef USE_GLFW // Collapse for clarity.
GLFWWindow::GLFWWindow(int width, int height, const char* title)
{
    if (!glfwInit())
        throw std::runtime_error("GLFW init failed");

    _window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!_window)
    {
        glfwTerminate();
        throw std::runtime_error("GLFWWindow creation failed");
    }

    glfwMakeContextCurrent(_window);

}

GLFWWindow::~GLFWWindow() 
{
    glfwDestroyWindow(_window);
    glfwTerminate();
}

bool GLFWWindow::Run()
{
    if(!_window) return false;

    while(!glfwWindowShouldClose(_window)) {
        glfwPollEvents();
        glfwSwapBuffers(_window);
    }
    return true;
}
#endif