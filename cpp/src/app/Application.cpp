#include "Application.h"

#include <iostream>
#include <fmt/core.h>

using namespace app; 


ParticleSandboxApplication::ParticleSandboxApplication()
{
    _mainWindow = graphics::WindowFactory::Create(graphics::WindowType::GLFW, 800,800, "Ma super fenêtre");
    _renderDevice = std::make_unique<graphics::OpenGLRenderDevice>();

    auto simulation = std::make_unique<core::SimpleSimulation>();

    auto solverPipeline = std::make_unique<core::SolverPipeline>();
    solverPipeline->AddSolver(std::make_unique<core::UpSolver>(0.2));

    simulation->Assign(std::move(solverPipeline));
    simulation->AddParticles(2);
    
    for(auto& particle : static_cast<core::SimpleContext&>(simulation->GetContext()).GetParticles())
        std::cout << fmt::format("Particle(x: {:.2f}, y: {:.2f})", particle.posX, particle.posY) << std::endl;

    _simulation = std::move(simulation);
}

ParticleSandboxApplication::~ParticleSandboxApplication()
{
}

bool ParticleSandboxApplication::Run()
{
    // if(!_mainWindow) return false;

    // if(!_mainWindow->Run())
    //     throw std::runtime_error("ParticleSandboxApplication Window failed to run");
    _simulation->Step(1.0f); // whatever.
    _simulation->Step(1.0f); // whatever.
    _simulation->Step(1.0f); // whatever.
    _simulation->Step(1.0f); // whatever.
    _simulation->Step(1.0f); // whatever.
    
    for(auto& particle : static_cast<core::SimpleContext&>(_simulation->GetContext()).GetParticles())
        std::cout << fmt::format("ParticleModified(x: {:.2f}, y: {:.2f})", particle.posX, particle.posY) << std::endl;



    return true;
}
