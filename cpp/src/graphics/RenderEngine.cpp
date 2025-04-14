#include "RenderEngine.h"

using namespace graphics;

#ifdef USE_OPENGL
#include <GL/gl.h>

OpenGLRenderEngine::OpenGLRenderEngine()
{
}

OpenGLRenderEngine::~OpenGLRenderEngine()
{
}

void OpenGLRenderEngine::FillScreen(const glm::vec3& color)
{
    glClearColor(color.r, color.g, color.b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

#endif