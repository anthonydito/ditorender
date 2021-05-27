#include "sphere.hpp"

using namespace dito::util;

Sphere::Sphere() {
    _origin = Point(0, 0, 0);
}

Point Sphere::origin() const
{
    return _origin;
}

bool Sphere::operator==(Sphere const &other) const
{
    return this == &other;
}

bool Sphere::operator!=(Sphere const &other) const
{
    return this != &other;
}
