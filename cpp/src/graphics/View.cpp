#include "View.h"

#include "common/Geometry.h"

using namespace graphics;

TestView::TestView(IRenderEngine& renderEngine) : _renderEngine(renderEngine)
{
    _triangleRenderer = std::make_unique<TriangleRenderer>(renderEngine);
}

TestView::~TestView()
{
}

void TestView::Update(float deltaTime)
{
    // Do nothing.
}

void TestView::Render()
{
    _renderEngine.FillScreen({ 0.0f, 0.7f, 0.5f });

    common::Triangle triangle {
        {0.f, 0.f, 0.f},
        {1.f, 0.f, 0.f},
        {0.f, 1.f, 0.f}
    };
    _triangleRenderer->Render(triangle);
}

Simple3DView::Simple3DView(IRenderEngine& renderEngine)
{
}

Simple3DView::~Simple3DView()
{
}

void Simple3DView::Update(float deltaTime)
{
    // Do nothing.
}

void Simple3DView::Render()
{
    // Do nothing.
}
