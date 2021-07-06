#include "computations.hpp"

using namespace dito::util;
using namespace dito::physics;

Computations::Computations(
    std::shared_ptr<Sphere> object,
    Point point,
    Vector eye_vector,
    Vector normal_vector,
    double t,
    bool inside)
{
    this->_object = object;
    this->_point = point;
    this->_eye_vector = eye_vector;
    this->_normal_vector = normal_vector;
    this->_t = t;
    this->_inside = inside;
}

std::shared_ptr<Sphere> Computations::object() const
{
    return this->_object;
}

Point Computations::point() const
{
    return this->_point;
}

Vector Computations::eye_vector() const
{
    return this->_eye_vector;
}

Vector Computations::normal_vector() const
{
    return this->_normal_vector;
}

double Computations::t() const
{
    return this->_t;
}

bool Computations::inside() const
{
    return this->_inside;
}