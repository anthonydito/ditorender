#include "material.hpp"

using namespace dito::physics;
using namespace dito::util;

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
