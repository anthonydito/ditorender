#include "color.hpp"

#include <cmath>

using namespace dito::util;

const double COMPARE_EPSILON = 0.000001;

Color::Color(double red, double green, double blue)
{
    this->_red = red;
    this->_green = green;
    this->_blue = blue;
}

double Color::red() const
{
    return _red;
}

double Color::green() const
{
    return _green;
}

double Color::blue() const
{
    return _blue;
}

Color Color::add(Color const &other) const
{
    return Color(this->red() + other.red(), this->green() + other.green(), this->blue() + other.blue());
}

Color Color::sub(Color const &other) const
{
    return Color(this->red() - other.red(), this->green() - other.green(), this->blue() - other.blue());
}

Color Color::mult(double scalar) const
{
    return Color(this->red() * scalar, this->green() * scalar, this->blue() * scalar);
}

Color Color::mult(Color const &other) const
{
    return Color(this->red() * other.red(), this->green() * other.green(), this->blue() * other.blue());
}

bool Color::eq(Color const &other) const
{
    return abs(this->red() - other.red()) < COMPARE_EPSILON &&
           abs(this->green() - other.green()) < COMPARE_EPSILON &&
           abs(this->blue() - other.blue()) < COMPARE_EPSILON;
}

Color Color::operator+(Color const &other) const
{
    return this->add(other);
}

Color Color::operator-(Color const &other) const
{
    return this->sub(other);
}

Color Color::operator*(double scalar) const
{
    return this->mult(scalar);
}

Color Color::operator*(Color const &other) const
{
    return this->mult(other);
}

bool Color::operator==(Color const &other) const
{
    return this->eq(other);
}

bool Color::operator!=(Color const &other) const {
    return !this->eq(other);
}
