#ifndef DITO_PHYSICS_INTERSECTION
#define DITO_PHYSICS_INTERSECTION

#include "../util/sphere.hpp"

namespace dito::physics
{
    class Intersection
    {
    public:
        Intersection(double, const dito::util::Sphere &);

        double t() const;
        const dito::util::Sphere &object() const;

    private:
        const dito::util::Sphere &_object;
        double _t;
    };
};

#endif