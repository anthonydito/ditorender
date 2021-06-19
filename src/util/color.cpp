#include "color.hpp"

#include <cmath>

using namespace dito::util;

const double COMPARE_EPSILON = 0.0001;

int clamp_double_to_255(double input)
{
    double multiplied = input * 255;
    if (multiplied > 255)
    {
        return 255;
    }
    else if (multiplied < 0)
    {
        return 0;
    }
    return round(multiplied);
}

Color::Color(double red, double green, double blue)
{
    this->_red = red;
    this->_green = green;
    this->_blue = blue;
}

Color Color::black()
{
    return Color(0, 0, 0);
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

int Color::red_255() const
{
    return clamp_double_to_255(this->red());
}

int Color::green_255() const
{
    return clamp_double_to_255(this->green());
}

int Color::blue_255() const
{
    return clamp_double_to_255(this->blue());
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

bool Color::operator!=(Color const &other) const
{
    return !this->eq(other);
}

std::ostream &dito::util::operator<<(std::ostream &os, const Color &c)
{
    os << "red=" << c.red() << ", green=" << c.green() << ", blue=" << c.blue() << std::endl;
    return os;
}
