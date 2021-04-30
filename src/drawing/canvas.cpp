#include "canvas.hpp"

using namespace dito::drawing;

Canvas::Canvas(int width, int height)
{
    this->_width = width;
    this->_height = height;

    for (int i = 0; i < width; ++i)
    {
        std::vector<dito::util::Color> new_vec;
        for (int j = 0; j < height; ++j)
        {
            new_vec.push_back(dito::util::Color(0, 0, 0));
        }
        this->_pixels.push_back(new_vec);
    }
}

int Canvas::width() const
{
    return this->_width;
}

int Canvas::height() const
{
    return this->_height;
}

dito::util::Color Canvas::pixel(int x, int y) const
{
    return this->_pixels[x][y];
}

void Canvas::set_pixel(int x, int y, dito::util::Color color)
{
    this->_pixels[x][y] = color;
}
