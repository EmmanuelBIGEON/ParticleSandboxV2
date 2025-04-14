#include "Scene.h"

#include <iostream>

using namespace graphics;

TestScene::TestScene()
{
}

TestScene::~TestScene()
{
}

void TestScene::Update(float deltaTime)
{
}

void TestScene::Render(IRenderEngine& renderEngine)
{
    renderEngine.FillScreen({ 0.0f, 0.7f, 0.5f });
}
