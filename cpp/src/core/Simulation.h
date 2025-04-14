#pragma once

#include <memory>

#include "Solver.h"

namespace core {
    //! \class ISimulation
    //! \brief An abstract class representing a simulation.
    class ISimulation {
        public:
            virtual ~ISimulation() = default;

            //! \brief Add a pipeline of solvers
            //! Might be stupid to not make it in constructor as it doesn't respect RAII but i don't like
            //! the idea of not being able to play with it.
            virtual void Assign(std::unique_ptr<SolverPipeline> pipeline) = 0;

            //! \brief Step the simulation.
            virtual void Step(float deltaTime) = 0;

            //! \brief Retrieve the context
            virtual IContext& GetContext() = 0;
            virtual const IContext& GetContext() const = 0;
    };

    //! \class SimpleSimulation
    //! \brief setting the base.
    class SimpleSimulation : public ISimulation {
        public:
            SimpleSimulation();
            virtual ~SimpleSimulation() override;
            
            virtual void Assign(std::unique_ptr<SolverPipeline> pipeline) override;
            virtual void Step(float deltaTime) override;
            virtual IContext& GetContext() override;
            virtual const IContext& GetContext() const override;
            
            void AddParticles(unsigned int count);
        
        protected:
            std::unique_ptr<SimpleContext> _context;
            std::unique_ptr<SolverPipeline> _solverPipeline;
    };
}