#ifndef DITO_UTIL_SPHERE
#define DITO_UTIL_SPHERE

#include "point.hpp"
#include "matrix.hpp"
#include "vector.hpp"
#include "../physics/material.hpp"

namespace dito::util
{
    class Sphere
    {
    public:
        Sphere();

        Point origin() const;
        Matrix transform() const;
        Vector normal_at(Point p) const;
        dito::physics::Material material() const;
        void set_material(dito::physics::Material);

        void set_transform(Matrix);
        bool operator==(Sphere const &other) const;
        bool operator!=(Sphere const &other) const;
        friend std::ostream &operator<<(std::ostream &os, const Sphere &m);

    private:
        Point _origin;
        Matrix _transform;
        dito::physics::Material _material;
    };
};

#endif