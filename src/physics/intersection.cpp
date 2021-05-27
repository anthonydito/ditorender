#include "intersection.hpp"

using namespace dito::util;
using namespace dito::physics;

const double COMPARE_EPSILON = 0.000001;

Intersection::Intersection(double t, const Sphere &object) : _object(object)
{
    this->_t = t;
}

double Intersection::t() const
{
    return _t;
}

const Sphere &Intersection::object() const
{
    return _object;
}

bool Intersection::eq(Intersection const &other) const {
    if (abs(t() - other.t()) > COMPARE_EPSILON) {
        return false;
    }
    return object() == other.object();
}

bool Intersection::operator==(Intersection const &other) const {
    return this->eq(other);
}

bool Intersection::operator!=(Intersection const &other) const {
    return !this->eq(other);
}
