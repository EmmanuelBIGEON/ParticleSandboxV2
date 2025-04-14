#include "Simulation.h"

using namespace core;


SimpleSimulation::SimpleSimulation()
{
    _context = std::make_unique<SimpleContext>();
}

SimpleSimulation::~SimpleSimulation()
{
}

void SimpleSimulation::Assign(std::unique_ptr<SolverPipeline> pipeline)
{
    _solverPipeline = std::move(pipeline);
}

void SimpleSimulation::Step(float deltaTime)
{
    _solverPipeline->Step(*_context, deltaTime);
}

IContext& SimpleSimulation::GetContext()
{
    return *_context;
}

const IContext& SimpleSimulation::GetContext() const
{
    return *_context;
}

void SimpleSimulation::AddParticles(unsigned int count) 
{
    ParticleGenerator generator(-100.0f, 100.0f, -100.0f, 100.0f); // for now.
    for (int i=0; i<count; ++i) // ++i seems better in some case than i++, so just always do it.
        _context->AddParticle(generator.Generate());
}