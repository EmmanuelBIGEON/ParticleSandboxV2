#include "Solver.h"

using namespace core;

SolverPipeline::SolverPipeline()
{
}

SolverPipeline::~SolverPipeline()
{
}

void SolverPipeline::AddSolver(std::unique_ptr<ISolver> solver)
{
    _solvers.emplace_back(std::move(solver));
}

void SolverPipeline::Step(IContext& context, float dt)
{
    for (auto& solver : _solvers)
        solver->Step(context, dt);
}

UpSolver::UpSolver(float value) : _value(value)
{
}

UpSolver::~UpSolver()
{
}

void UpSolver::Step(IContext& context, float deltaTime)
{
    if(context.GetType() != ContextType::SimpleContext) throw std::runtime_error("UpSolver requires SimpleContext");
    SimpleContext* simpleContext = static_cast<SimpleContext*>(&context);

    for(auto& particle : simpleContext->GetParticles()) {
        particle.posY += _value;
    }
}
