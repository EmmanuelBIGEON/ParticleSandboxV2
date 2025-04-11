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
