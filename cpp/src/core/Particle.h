#pragma once

#include <random>

namespace core {
    //! \class Particle
    //! \brief A spatial entity.
    class Particle {
        public:
            float posX;
            float posY;
    };

    //! \class ParticleGenerator
    //! \brief Generate particle in specified bounds
    class ParticleGenerator
    {
    public:
        ParticleGenerator(float minX, float maxX, float minY, float maxY);
        virtual ~ParticleGenerator() = default;

        Particle Generate();

    private:
        std::mt19937 _randomEngine;
        std::uniform_real_distribution<float> _distX;
        std::uniform_real_distribution<float> _distY;
    };
}
