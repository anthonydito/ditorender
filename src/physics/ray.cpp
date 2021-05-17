#include "ray.hpp"

using namespace dito::util;
using namespace dito::physics;

Ray::Ray(Point origin, Vector direction)
{
    this->_origin = origin;
    this->_direction = direction;
}

Point Ray::origin() const 
{
    return this->_origin;
}

Vector Ray::direction() const
{
    return this->_direction;
}

Point Ray::position(double time) const
{
    return this->origin() + (this->direction() * time);
}