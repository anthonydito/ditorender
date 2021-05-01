#include "../util/point.hpp"
#include "../util/vector.hpp"
#include "../sim/environment.hpp"
#include "../sim/projectile.hpp"
#include "../drawing/canvas.hpp"
#include "../util/color.hpp"
#include <iostream>

using namespace dito::util;
using namespace dito::drawing;
using namespace dito::sim;

int main()
{

    Point start(0, 1, 0);
    Vector velocity = Vector(1, 1.8, 0).normalize() * 11.25;
    Projectile p(start, velocity);

    Vector gravity = Vector(0, -0.1, 0);
    Vector wind = Vector(-0.01, 0, 0);
    Environment e(gravity, wind);

    Canvas c(900, 550);

    Color drawing_color(1, 0, 0);

    while (p.position().y() > 0)
    {
        c.set_pixel(p.position().x(), c.height() - p.position().y(), drawing_color);
        p.tick(e);
    }

    std::cout << "about to draw file" << std::endl;

    c.to_ppm_file("test.ppm");

    std::cout << "FINISHED CREATING" << std::endl;

}