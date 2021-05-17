#include <iostream>

#include "../drawing/canvas.hpp"
#include "../util/point.hpp"
#include "../util/matrix.hpp"

using namespace dito::util;
using namespace dito::drawing;

int main()
{
    Canvas c(500, 500);
    Point curr(0, 200, 0);
    Color drawing_color(1, 0, 0);
    Matrix rotation_matrix = Matrix::rotation_z(M_PI / 6);
    for (int i = 0; i < 12; ++i)
    {
        c.set_pixel(250 - curr.x(), 250 - curr.y(), drawing_color);
        curr = (rotation_matrix * curr).to_point();
    }
    c.to_ppm_file("/Users/dito/Desktop/curr.ppm");
}