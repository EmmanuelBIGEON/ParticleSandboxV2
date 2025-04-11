#pragma once

#include <memory>

#include "Solver.h"

namespace core {
    //! \class ISimulation
    //! \brief An abstract class representing a simulation.
    class ISimulation {
        public:
            virtual ~ISimulation() = default;

            //! \brief Step the simulation.
            virtual void Step(float deltaTime) = 0;
    };
}