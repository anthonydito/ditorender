#include "point_light.hpp"

using namespace dito::util;
using namespace dito::physics;

PointLight::PointLight(Point position, Color intensity) : _position(position), _intensity(intensity)
{
}

Point PointLight::position() const
{
    return _position;
}

Color PointLight::intensity() const
{
    return _intensity;
}

bool PointLight::operator==(PointLight const &other) const {
    return this->position() == other.position() && this->intensity() == other.intensity();
}
