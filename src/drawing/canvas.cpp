#include "canvas.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

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

std::string Canvas::to_ppm()
{
    std::stringstream result;
    result << "P3\n";
    result << this->width() << " " << this->height() << "\n";
    result << 255 << "\n";

    for (int row = 0; row < this->height(); ++row)
    {
        std::stringstream row_data;
        int curr_size = 0;
        for (int col = 0; col < this->width(); ++col)
        {
            auto color = this->pixel(col, row);
            std::string red = std::to_string(color.red_255());
            std::string blue = std::to_string(color.blue_255());
            std::string green = std::to_string(color.green_255());
            std::vector<std::string> numbers_to_write{red, green, blue};
            for (auto number_to_write : numbers_to_write)
            {
                if (curr_size + number_to_write.size() + 1 > 70)
                {
                    row_data << "\n";
                    curr_size = 0;
                } else if (curr_size != 0) {
                    row_data << " ";
                    curr_size += 1;
                }
                row_data << number_to_write;
                curr_size += number_to_write.size();
            }
        }
        result << row_data.str() << "\n";
    }

    return result.str();
}

void Canvas::to_ppm_file(std::string filename)
{
    std::string ppm = this->to_ppm();
    std::ofstream out(filename);
    out << ppm;
    out.close();
}
