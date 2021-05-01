#include "environment.hpp"

using namespace dito::util;
using namespace dito::sim;

Environment::Environment(Vector gravity, Vector wind)
{
    _wind = wind;
    _gravity = gravity;
}

Vector Environment::gravity()
{
    return this->_gravity;
}

Vector Environment::wind()
{
    return this->_wind;
}