#include "sphere.hpp"

using namespace dito::util;

Sphere::Sphere() : _transform(Matrix::identity_matrix(4))
{
    _origin = Point(0, 0, 0);
}

Point Sphere::origin() const
{
    return _origin;
}

Matrix Sphere::transform() const
{
    return _transform;
}

void Sphere::set_transform(Matrix transform)
{
    _transform = transform;
}

bool Sphere::operator==(Sphere const &other) const
{
    return this == &other;
}

bool Sphere::operator!=(Sphere const &other) const
{
    return this != &other;
}

Vector Sphere::normal_at(Point p) const
{
    return (p - this->origin()).to_vector();
}
