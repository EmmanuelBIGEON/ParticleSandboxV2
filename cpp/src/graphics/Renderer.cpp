#include "Renderer.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <fmt/core.h>

#include "util/Filesystem.h"

using namespace graphics;

TriangleRenderer::TriangleRenderer(IRenderEngine& renderEngine) : _renderEngine(renderEngine)
{
    _vertexArray = _renderEngine.CreateVertexArray();
    _vertexBuffer = _renderEngine.CreateVertexBuffer();
    _vertexArray->Bind();
    _vertexBuffer->Bind();
    _vertexArray->SetAttribute(0, 2, rhi::VertexAttribType::Float32, false, 2 * sizeof(float), 0);
}

TriangleRenderer::~TriangleRenderer()
{
}

void TriangleRenderer::SetTriangle(const common::Triangle& triangle)
{
    _vertexArray->Bind();
    _vertexBuffer->Bind();
    _dataArray = {
        triangle.p1.x, triangle.p1.y,
        triangle.p2.x, triangle.p2.y,
        triangle.p3.x, triangle.p3.y
    };
    _vertexBuffer->SetData(_dataArray.data(), _dataArray.size() * sizeof(float), rhi::VertexBufferUsage::Static);
}

void TriangleRenderer::Render() {
    _renderEngine.BindShader(ShaderType::Basic);
    _vertexArray->Bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

RectangleRenderer::RectangleRenderer(IRenderEngine& renderEngine) : _renderEngine(renderEngine)
{
}

RectangleRenderer::~RectangleRenderer()
{
}

void RectangleRenderer::Render() {}

CubeRenderer::CubeRenderer(IRenderEngine& renderEngine) : _renderEngine(renderEngine)
{
}

CubeRenderer::~CubeRenderer()
{
}

void CubeRenderer::Render() {}