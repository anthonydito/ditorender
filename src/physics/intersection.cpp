#include "intersection.hpp"

using namespace dito::util;
using namespace dito::physics;

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
