#include "Window.h"

using namespace graphics;

#ifdef USE_GLFW // Collapse for clarity.
GLFWWindow::GLFWWindow(int width, int height, const char* title)
{
}

GLFWWindow::~GLFWWindow() 
{
}


bool GLFWWindow::Init()
{
    return false;
}

bool GLFWWindow::Run()
{
    return false;
}

bool GLFWWindow::Destroy()
{
    return false;
}


void GLFWWindow::Display()
{
}

void GLFWWindow::Hide()
{
}
#endif