#include "../util/point.hpp"
#include "../util/vector.hpp"
#include "../drawing/canvas.hpp"
#include "../util/color.hpp"
#include "../physics/ray.hpp"
#include "../physics/intersections.hpp"
#include "../physics/material.hpp"
#include <iostream>

using namespace dito::util;
using namespace dito::drawing;
using namespace dito::physics;

int main()
{
    Sphere s;
    Material m;
    m.set_color(Color(1, 0.2, 1));
    s.set_material(m);

    Point light_position = Point(-10, 10, -10);
    Color light_color = Color(1, 1, 1);
    PointLight light = PointLight(light_position, light_color);

    Canvas c(500, 500);
    s.set_transform(Matrix::scaling(1.5, 1.5, 1.5));

    Point camera_origin = Point(0, 0, -2);
    double shadow_wall_z = 30;

    Color drawing_color(1, 0, 0);

    int half_width = c.width() / 2;
    int half_height = c.height() / 2;

    std::cout << "starting render" << std::endl;

    for (int w = -half_width; w < half_width; ++w)
    {
        for (int h = -half_height; h < half_height; ++h)
        {
            Point end_point = Point(w, h, shadow_wall_z);
            Vector direction = (end_point - camera_origin).to_vector().normalize();
            Ray r(camera_origin, direction);
            auto hit = r.intersets(s).hit();
            if (hit.has_value()) {
                Point point = r.position(hit.value().t());
                Vector normal = hit.value().object().normal_at(point);
                Vector eye = r.direction().negate().to_vector();

                auto color = hit.value().object().material().lighting(light, point, eye, normal);

                c.set_pixel(w + half_width, half_height - h, color);
            }
        }
        std::cout << "finished rendering row " << w + half_width << std::endl;
    }
    std::cout << "finished 2" << std::endl;
    c.to_ppm_file("sphere2.ppm");
}