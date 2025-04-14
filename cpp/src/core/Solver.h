#pragma once

#include <memory>
#include <vector>

#include "Context.h"

namespace core {
    //! \class ISolver
    //! \brief An abstract class representing a solver.
    //! A solver is used to compute the evolution of the context.
    class ISolver {
        public:
            virtual ~ISolver() = default;

            //! \brief Calculate the evolution
            virtual void Step(IContext& context, float deltaTime) = 0;
    };

    //! \class SolverPipeline
    //! \brief A stack of solvers
    class SolverPipeline {
        public:
            SolverPipeline();
            virtual ~SolverPipeline();

            void AddSolver(std::unique_ptr<ISolver> solver);
            
            void Step(IContext& context, float dt);

        protected:
            std::vector<std::unique_ptr<ISolver>> _solvers;
    };

    //! \class UpSolver
    //! \brief Move up particles.
    class UpSolver : public ISolver {
        public:
            UpSolver(float value);
            virtual ~UpSolver();

            virtual void Step(IContext& context, float deltaTime) override;
        protected:
            float _value;
    };
}