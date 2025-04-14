#include "Particle.h"

using namespace core;


ParticleGenerator::ParticleGenerator(float minX, float maxX, float minY, float maxY)
    : _distX(minX, maxX), _distY(minY, maxY), _randomEngine(std::random_device{}())
{
}

Particle ParticleGenerator::Generate()
{
    return Particle(_distX(_randomEngine), _distY(_randomEngine));
}