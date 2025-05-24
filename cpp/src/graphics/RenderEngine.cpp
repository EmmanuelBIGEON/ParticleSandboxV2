#include "RenderEngine.h"

using namespace graphics;

#ifdef USE_OPENGL

OpenGLRenderEngine::OpenGLRenderEngine()
{
}

OpenGLRenderEngine::~OpenGLRenderEngine()
{
}

std::unique_ptr<rhi::IVertexBuffer> OpenGLRenderEngine::CreateVertexBuffer()
{
    return std::make_unique<rhi::OpenGLVertexBuffer>();
}

std::unique_ptr<rhi::IVertexArray> OpenGLRenderEngine::CreateVertexArray()
{
    return std::make_unique<rhi::OpenGLVertexArray>();
}

std::shared_ptr<rhi::IShader> OpenGLRenderEngine::CreateShader(const std::string& vertexSource, const std::string& fragmentSource)
{
    return std::make_shared<rhi::OpenGLShader>(vertexSource, fragmentSource);
}

void OpenGLRenderEngine::FillScreen(const glm::vec3& color)
{
    glClearColor(color.r, color.g, color.b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLRenderEngine::DrawArrays(DrawMode topology, int count)
{
    GLenum glMode = GL_TRIANGLES;
    switch (topology) {
        case DrawMode::Triangles: glMode = GL_TRIANGLES; break;
        case DrawMode::Lines:     glMode = GL_LINES;     break;
        case DrawMode::LineStrip: glMode = GL_LINE_STRIP; break;
    }

    glDrawArrays(glMode, 0, count);
}
#endif