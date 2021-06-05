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

void Material::set_color(Color color)
{
    _color = color;
}

bool Material::operator==(const Material &other) const {
    return other.color() == this->color() && 
        abs(ambient() - other.ambient()) < COMPARE_EPSILON &&
        abs(diffuse() - other.diffuse()) < COMPARE_EPSILON &&
        abs(specular() - other.specular()) < COMPARE_EPSILON &&
        abs(shininess() - other.shininess()) < COMPARE_EPSILON;
}

Color Material::lighting(PointLight pl, Point p, Vector eye_vector, Vector normal_vector) const
{

    auto effective_color = this->color() * pl.intensity();
    auto light_v = (pl.position() - p).to_vector().normalize();
    auto ambient = effective_color * this->ambient();

    auto light_dot_normal = light_v.dot(normal_vector);

    Color diffuse = Color::black();
    Color specular = Color::black();

    // light is NOT on the other side of the surface
    if (light_dot_normal >= 0) {
        diffuse = effective_color * this->diffuse() * light_dot_normal;

        Vector reflect_v = light_v.negate().to_vector().reflect(normal_vector);
        auto reflect_dot_eye = reflect_v.dot(eye_vector);

        if (reflect_dot_eye != 0) {
            auto factor = pow(reflect_dot_eye, this->shininess());
            specular = pl.intensity() * this->specular() * factor;
        }
    }

    return ambient + diffuse + specular;
}
