#include "tuple.hpp"
#include "point.hpp"

#include <cmath>

using namespace dito::util;

const double COMPARE_EPSILON = 0.000001;

Tuple::Tuple(const Point p)
{
    this->_x = p.x();
    this->_y = p.y();
    this->_z = p.z();
    this->_z = p.w();
}

Tuple::Tuple(const Tuple &t)
{
    this->_x = t.x();
    this->_y = t.y();
    this->_z = t.z();
    this->_z = t.w();
}

Tuple::Tuple(double x, double y, double z, double w)
{
    this->_x = x;
    this->_y = y;
    this->_z = z;
    this->_w = w;
}

double Tuple::x() const
{
    return _x;
}

double Tuple::y() const
{
    return _y;
}

double Tuple::z() const
{
    return _z;
}

double Tuple::w() const
{
    return _w;
}

Tuple Tuple::sub(const Tuple &other) const
{
    return Tuple(
        this->x() - other.x(),
        this->y() - other.y(),
        this->z() - other.z(),
        this->w() - other.w());
}

Tuple Tuple::add(const Tuple &other) const
{
    return Tuple(
        this->x() + other.x(),
        this->y() + other.y(),
        this->z() + other.z(),
        this->w() + other.w());
}

bool Tuple::eq(const Tuple &other) const
{
    return abs(this->x() - other.x()) < COMPARE_EPSILON &&
           abs(this->y() - other.y()) < COMPARE_EPSILON &&
           abs(this->z() - other.z()) < COMPARE_EPSILON &&
           abs(this->w() - other.w()) < COMPARE_EPSILON;
}

Tuple Tuple::negate() const
{
    return Tuple(-this->x(), -this->y(), -this->z(), -this->w());
}

Tuple Tuple::multiply(double scalar) const
{
    return Tuple(this->x() * scalar, this->y() * scalar, this->z() * scalar, this->w() * scalar);
}

Tuple Tuple::divide(double scalar) const
{
    return this->multiply(1 / scalar);
}

std::ostream &operator<<(std::ostream &os, const Tuple &obj)
{
    os << "x=" << obj.x() << ", y=" << obj.y() << ", z=" << obj.z() << ", w=" << obj.w();
    return os;
}

Tuple Tuple::operator+(Tuple const &other) const
{
    return this->add(other);
}

Tuple Tuple::operator-(Tuple const &other) const
{
    return this->sub(other);
}

bool Tuple::operator==(Tuple const &other) const
{
    return this->eq(other);
}

Tuple Tuple::operator*(double scalar) const
{
    return this->multiply(scalar);
}

std::ostream &dito::util::operator<<(std::ostream &os, const Tuple &t)
{
    os << "Tuple: x=" <<t.x() << ", y=" << t.y() << ", z=" << t.z() << ", w=" << t.w() << std::endl;
    return os;
}
