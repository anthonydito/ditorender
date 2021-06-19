#include "sphere.hpp"

#include "matrix.hpp"

using namespace dito::util;
using namespace dito::physics;

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
    Matrix transform_inverse = this->transform().inverse();
    Tuple object_point = transform_inverse * p;
    Tuple object_normal = object_point - this->origin();
    Tuple world_normal = transform_inverse.transpose() * object_normal;
    return Vector(world_normal.x(), world_normal.y(), world_normal.z()).normalize();
}

Material Sphere::material() const {
    return _material;
}

void Sphere::set_material(Material material)
{
    _material = material;
}

std::ostream &dito::util::operator<<(std::ostream &os, const Sphere &s)
{
    os << "transform:" << std::endl;
    os << s.transform();
    os << "point:" << std::endl;
    os << s.origin() << std::endl;;
    return os;
}
