#include "Renderer.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <fmt/core.h>

#include "util/Filesystem.h"

using namespace graphics;

TriangleRenderer::TriangleRenderer(IRenderEngine& renderEngine) : _renderEngine(renderEngine)
{
    // util::displayDirectory(".");
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile("./shaders/basic.vs");
    std::ifstream fShaderFile("./shaders/basic.fs"); 
    std::stringstream vShaderStream, fShaderStream;
    vShaderStream << vShaderFile.rdbuf();
    fShaderStream << fShaderFile.rdbuf();
    vShaderFile.close();
    fShaderFile.close();
    vertexCode = vShaderStream.str();
    fragmentCode = fShaderStream.str(); 
    fmt::print("vertexCode: {}\n", vertexCode.size());
    fmt::print("fragmentCode: {}\n", fragmentCode.size());
    _shaderTriangle = renderEngine.CreateShader(vertexCode, fragmentCode);
    
    _shaderTriangle->Bind();
    _vertexArray = _renderEngine.CreateVertexArray();
    _vertexArray->Bind();
}

TriangleRenderer::~TriangleRenderer()
{
}

void TriangleRenderer::Render(const common::Triangle& triangle)
{
    _shaderTriangle->Bind();
    _vertexArray->Bind();
    auto vertexBuffer = _renderEngine.CreateVertexBuffer();
    vertexBuffer->Bind();
    float data[6] = {
        triangle.p1.x, triangle.p1.y,
        triangle.p2.x, triangle.p2.y,
        triangle.p3.x, triangle.p3.y
    };
    vertexBuffer->SetData(data, sizeof(data), rhi::VertexBufferUsage::Static);
    _vertexArray->SetAttribute(0, 2, rhi::VertexAttribType::Float32, false, 2 * sizeof(float), 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

RectangleRenderer::RectangleRenderer(IRenderEngine& renderEngine) : _renderEngine(renderEngine)
{
}

RectangleRenderer::~RectangleRenderer()
{
}

CubeRenderer::CubeRenderer(IRenderEngine& renderEngine) : _renderEngine(renderEngine)
{
}

CubeRenderer::~CubeRenderer()
{
}
