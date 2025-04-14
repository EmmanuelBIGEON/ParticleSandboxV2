#include "Renderer.h"

using namespace graphics;

TriangleRenderer::TriangleRenderer(IRenderEngine& renderEngine) : _renderEngine(renderEngine)
{
}

TriangleRenderer::~TriangleRenderer()
{
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
