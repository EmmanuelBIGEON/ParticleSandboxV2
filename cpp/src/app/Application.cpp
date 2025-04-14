#include "Application.h"

#include <iostream>

using namespace app; 

#include "graphics/Scene.h"

ParticleSandboxApplication::ParticleSandboxApplication()
{
    _mainWindow = graphics::WindowFactory::Create(graphics::WindowType::GLFW, 800, 800, "Ma super fenêtre");
    _mainWindow->SetScene(std::move(std::make_unique<graphics::TestScene>()));
}

ParticleSandboxApplication::~ParticleSandboxApplication()
{
}

bool ParticleSandboxApplication::Run()
{
    if(!_mainWindow) return false;

    if(!_mainWindow->Run())
        throw std::runtime_error("ParticleSandboxApplication Window failed to run");

    return true;
}
