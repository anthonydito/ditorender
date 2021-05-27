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
        bool eq(Intersection const &other) const;
        bool operator==(Intersection const &other) const;
        bool operator!=(Intersection const &other) const;

    private:
        const dito::util::Sphere &_object;
        double _t;
    };
};

#endif