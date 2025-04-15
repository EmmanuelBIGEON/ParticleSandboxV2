#include "Scene.h"

#include <iostream>
#include <fmt/core.h>

using namespace graphics;

TestScene::TestScene(IRenderEngine& renderEngine)
{
    auto simulation = std::make_unique<core::SimpleSimulation>();

    auto solverPipeline = std::make_unique<core::SolverPipeline>();
    solverPipeline->AddSolver(std::make_unique<core::UpSolver>(0.2));

    simulation->Assign(std::move(solverPipeline));
    simulation->AddParticles(2);

    for(auto& particle : static_cast<core::SimpleContext&>(simulation->GetContext()).GetParticles())
        std::cout << fmt::format("Particle(x: {:.2f}, y: {:.2f})", particle.posX, particle.posY) << std::endl;

    _simulation = std::move(simulation);

    _view = std::make_unique<TestView>(renderEngine);
}

TestScene::~TestScene()
{
}

void TestScene::Update(float deltaTime)
{
    // _simulation->Step(1.0f); // whatever.
}

void TestScene::Render()
{
    _view->Render();
}
