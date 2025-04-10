#include "Application.h"

using namespace app; 


ParticleSandboxApplication::ParticleSandboxApplication()
{
    _mainWindow = graphics::WindowFactory::Create(graphics::WindowType::GLFW, 800,800, "Ma super fenêtre");
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
