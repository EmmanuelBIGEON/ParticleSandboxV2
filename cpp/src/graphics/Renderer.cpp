#include "Renderer.h"

#include <iostream>

using namespace graphics;

TriangleRenderer::TriangleRenderer(IRenderEngine& renderEngine) : _renderEngine(renderEngine)
{
}

TriangleRenderer::~TriangleRenderer()
{
}

void TriangleRenderer::Render(const common::Triangle& triangle)
{
    std::cout << "Rendering Triangle" << std::endl;
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
