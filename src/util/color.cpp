#include "color.hpp"

using namespace dito::util;

Color::Color(double red, double green, double blue) {
    this->_red = red;
    this->_green = green;
    this->_blue = blue;
}

double Color::red()
{
    return _red;
}

double Color::green()
{
    return _green;
}

double Color::blue() 
{
    return _blue;
}
