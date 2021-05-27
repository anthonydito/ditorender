#ifndef DITO_PHYSICS_RAY
#define DITO_PHYSICS_RAY

#include <vector>
#include "../util/point.hpp"
#include "../util/vector.hpp"
#include "../util/sphere.hpp"

namespace dito::physics
{
    class Ray
    {
        public:
            Ray(dito::util::Point point, dito::util::Vector direction);

            dito::util::Point origin() const;
            dito::util::Vector direction() const;
            dito::util::Point position(double time) const;
            std::vector<double> intersets(dito::util::Sphere) const;

        private:
            dito::util::Point _origin;
            dito::util::Vector _direction;
    };
};

#endif