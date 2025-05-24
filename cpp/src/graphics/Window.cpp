#include "Window.h"

#include <iostream>
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
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_SAMPLES, 4);
    if (!glfwInit())
        throw std::runtime_error("GLFW init failed");

    _window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!_window)
    {
        glfwTerminate();
        throw std::runtime_error("GLFWWindow creation failed");
    }

    glfwMakeContextCurrent(_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){ std::cout << "Failed to initialize GLAD" << std::endl; return; }

    _renderEngine = std::make_unique<graphics::OpenGLRenderEngine>();
}

GLFWWindow::~GLFWWindow() 
{
    glfwDestroyWindow(_window);
    glfwTerminate();
}

bool GLFWWindow::Run()
{
    if (!_window)
        return false;

    constexpr double targetDeltaTime = 1.0 / 60.0; // 60 FPS
    double lastTime = glfwGetTime();
    double accumulator = 0.0;

    while (!glfwWindowShouldClose(_window))
    {
        double currentTime = glfwGetTime();
        double frameTime = currentTime - lastTime;
        lastTime = currentTime;

        accumulator += frameTime;

        glfwPollEvents();

        while (accumulator >= targetDeltaTime)
        {
            _scene->Update(static_cast<float>(targetDeltaTime));
            accumulator -= targetDeltaTime;
        }

        _scene->Render();

        glfwSwapBuffers(_window);
    }

    return true;
}

void GLFWWindow::SetScene(std::unique_ptr<IScene> scene)
{
    _scene = std::move(scene);
}

IRenderEngine& GLFWWindow::GetRenderEngine()
{
    return *_renderEngine;
}
#endif