#include "projectile.hpp"

using namespace dito::sim;
using namespace dito::util;

Projectile::Projectile(Point start_position, Vector velocity)
{
    _position = start_position;
    _velocity = velocity;
}

Point Projectile::position()
{
    return _position;
}

void Projectile::tick(Environment environment)
{
    _position = _position + _velocity;
    _velocity = (_velocity + environment.gravity() + environment.wind()).to_vector();
}
