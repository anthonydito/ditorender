#include "../util/point.hpp"
#include "../util/vector.hpp"
#include "../drawing/canvas.hpp"
#include "../util/color.hpp"
#include "../physics/ray.hpp"
#include "../physics/intersections.hpp"
#include <iostream>

using namespace dito::util;
using namespace dito::drawing;
using namespace dito::physics;

int main()
{
    Sphere s;
    Canvas c(200, 200);
    s.set_transform(Matrix::scaling(1, 0.5, 1));

    Point camera_origin = Point(0, 0, -3);
    double shadow_wall_z = 50;

    Color drawing_color(1, 0, 0);

    int half_width = c.width() / 2;
    int half_height = c.height() / 2;

    std::cout << "starting render 2" << std::endl;

    for (int w = -half_width; w < half_width; ++w)
    {
        for (int h = -half_height; h < half_height; ++h)
        {
            Point end_point = Point(w, h, shadow_wall_z);
            Vector direction = (end_point - camera_origin).to_vector().normalize();
            Ray r(camera_origin, direction);
            bool hasHit = r.intersets(s).hit().has_value();
            if (hasHit) {
                c.set_pixel(w + half_width, half_height - h, drawing_color);
            }
        }
        std::cout << "finished rendering row " << w + half_width << std::endl;
    }
    std::cout << "finished" << std::endl;
    c.to_ppm_file("sphere.ppm");
}
