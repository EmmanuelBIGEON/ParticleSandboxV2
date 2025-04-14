#include "View.h"

using namespace graphics;

TestView::TestView(IRenderEngine& renderEngine)
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
    // Do nothing.
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
