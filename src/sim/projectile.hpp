#ifndef DITO_SIM_PROJECTILE
#define DITO_SIM_PROJECTILE

#include "../util/vector.hpp"
#include "../util/point.hpp"
#include "environment.hpp"

namespace dito::sim
{
    class Projectile {
    public:
        Projectile(dito::util::Point, dito::util::Vector);

        void tick(dito::sim::Environment environment);
        dito::util::Point position();

    private:
        dito::util::Point _position;
        dito::util::Vector _velocity;
    };
}

#endif