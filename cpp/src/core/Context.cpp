#include "Context.h"

using namespace core;

SimpleContext::SimpleContext()
{
}

SimpleContext::~SimpleContext()
{
}

void SimpleContext::Clear()
{
}

ContextType SimpleContext::GetType() const
{
    return ContextType::SimpleContext;
}

void SimpleContext::AddParticle(const Particle& particle)
{
    _particles.emplace_back(particle);
}

void SimpleContext::AddParticle(Particle&& particle)
{
    _particles.emplace_back(std::move(particle));
}

std::vector<Particle>& SimpleContext::GetParticles()
{
    return _particles;
}