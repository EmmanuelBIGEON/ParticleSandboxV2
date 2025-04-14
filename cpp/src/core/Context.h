#pragma once

#include <vector>

#include "Particle.h"

namespace core {
    enum class ContextType { SimpleContext };

    //! \class IContext
    //! \brief An abstract class representing a context.
    //! Contains data that can be processed through solvers.
    class IContext {
        public:
            virtual ~IContext() = default;

            //! \brief Empty the context.
            virtual void Clear() = 0;

            //! \brief return context type.
            virtual ContextType GetType() const = 0;
    };

    //! \class SimpleContext
    //! \brief Unoptimized POC context.
    class SimpleContext : public IContext {
        public:
            SimpleContext();
            virtual ~SimpleContext() override;

            virtual void Clear() override;
            virtual ContextType GetType() const override;

            void AddParticle(Particle&& particle);
            void AddParticle(const Particle& particle);

            std::vector<Particle>& GetParticles();
        protected:
            std::vector<Particle> _particles;
    };
}