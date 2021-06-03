#include "material.hpp"

#include <math.h>

using namespace dito::physics;
using namespace dito::util;

const double COMPARE_EPSILON = 0.000001;

Material::Material() : _color(Color(1, 1, 1)), _ambient(0.1), _diffuse(0.9), _specular(0.9), _shininess(200)
{
}

double Material::ambient() const
{
    return _ambient;
}

double Material::diffuse() const
{
    return _diffuse;
}

double Material::specular() const
{
    return _specular;
}

double Material::shininess() const
{
    return _shininess;
}

Color Material::color() const
{
    return _color;
}

bool Material::operator==(const Material &other) const {
    return other.color() == this->color() && 
        abs(ambient() - other.ambient()) < COMPARE_EPSILON &&
        abs(diffuse() - other.diffuse()) < COMPARE_EPSILON &&
        abs(specular() - other.specular()) < COMPARE_EPSILON &&
        abs(shininess() - other.shininess()) < COMPARE_EPSILON;
}
