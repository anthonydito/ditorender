#ifndef DITO_PHYSICS_RAY
#define DITO_PHYSICS_RAY

#include <vector>
#include "../util/point.hpp"
#include "../util/vector.hpp"
#include "../util/sphere.hpp"
#include "../util/matrix.hpp"
#include "../util/color.hpp"
#include "computations.hpp"
#include "intersections.hpp"
#include "world.hpp"

namespace dito::physics
{
    class Ray
    {
        public:
            Ray(dito::util::Point point, dito::util::Vector direction);

            dito::util::Point origin() const;
            dito::util::Vector direction() const;
            dito::util::Point position(double time) const;
            Intersections intersects(dito::physics::World &) const;
            Intersections intersets(std::shared_ptr<dito::util::Sphere>) const;
            Computations prepare_computations(Intersection intersection) const;
            Ray transform(dito::util::Matrix) const;
            dito::util::Color color_at(dito::physics::World &) const;

        private:
            dito::util::Point _origin;
            dito::util::Vector _direction;
    };
};

#endif