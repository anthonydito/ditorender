#ifndef DITO_PHYSICS_RAY
#define DITO_PHYSICS_RAY

#include "../util/point.hpp"
#include "../util/vector.hpp"

namespace dito::physics
{
    class Ray
    {
        public:
            Ray(dito::util::Point point, dito::util::Vector direction);

            dito::util::Point origin() const;
            dito::util::Vector direction() const;
            dito::util::Point position(double time) const;

        private:
            dito::util::Point _origin;
            dito::util::Vector _direction;
    };
};

#endif