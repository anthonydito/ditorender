#include <iostream>

#include "../sim/environment.hpp"
#include "../sim/projectile.hpp"

using namespace dito::sim;
using namespace dito::util;

int main()
{
    Projectile p = Projectile(Point(0, 1, 0), Vector(1, 1, 0).normalize());
    Environment e = Environment(Vector(0, -0.1, 0), Vector(-0.01, 0, 0));
    while (p.position().y() >= 0)
    {
        std::cout << "x=" << p.position().x() << ", y=" << p.position().y() << ", z=" << p.position().z() << std::endl;
        p.tick(e);
    }
}