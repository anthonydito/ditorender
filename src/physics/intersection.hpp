#ifndef DITO_PHYSICS_INTERSECTION
#define DITO_PHYSICS_INTERSECTION

#include <memory>
#include "../util/sphere.hpp"

namespace dito::physics
{
    class Intersection
    {
    public:
        Intersection(double, std::shared_ptr<dito::util::Sphere>);

        double t() const;
        std::shared_ptr<dito::util::Sphere> object() const;
        bool eq(Intersection const &other) const;
        bool operator==(Intersection const &other) const;
        bool operator!=(Intersection const &other) const;
        bool operator<(Intersection const & other) const;

    private:
        std::shared_ptr<dito::util::Sphere> _object;
        double _t;
    };
};

#endif