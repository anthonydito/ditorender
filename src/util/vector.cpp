#include "vector.hpp"

#include <cmath>
#include <stdexcept>

using namespace dito::util;

Vector::Vector() : Vector(0, 0, 0) {}

Vector::Vector(double x, double y, double z) : Tuple(x, y, z, 0) {}

Vector Tuple::to_vector() const
{
    if (this->w() != 0)
    {
        throw std::invalid_argument("w should be 0 for vector");
    }
    return Vector(this->x(), this->y(), this->z());
}

double Vector::magnitude() const
{
    double x = this->x();
    double y = this->y();
    double z = this->z();
    double w = this->w();
    return sqrt((x * x) + (y * y) + (z * z) + (w * w));
}

Vector Vector::normalize() const
{
    return this->divide(this->magnitude()).to_vector();
}

double Vector::dot(const Vector &other) const 
{
    double output = 0;
    output += this->x() * other.x();
    output += this->y() * other.y();
    output += this->z() * other.z();
    output += this->w() * other.w();
    return output;
}

Vector Vector::cross(const Vector &other) const {
    double x_comp = (this->y() * other.z()) - (this->z() * other.y());
    double y_comp = (this->z() * other.x()) - (this->x() * other.z());
    double z_comp = (this->x() * other.y()) - (this->y() * other.x());
    return Vector(x_comp, y_comp, z_comp);
}

Vector Vector::operator*(double scalar) const
{
    return this->multiply(scalar).to_vector();
}
