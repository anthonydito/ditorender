#include <gtest/gtest.h>

#include "canvas.hpp"

using namespace dito::drawing;

std::vector<std::string> string_to_lines(std::string input)
{
    std::vector<std::string> strings;

    std::string::size_type pos = 0;
    std::string::size_type prev = 0;
    while ((pos = input.find("\n", prev)) != std::string::npos)
    {
        strings.push_back(input.substr(prev, pos - prev));
        prev = pos + 1;
    }
    strings.push_back(input.substr(prev));
    return strings;
}

TEST(Canvas, Initializer)
{
    Canvas c(10, 20);
    EXPECT_EQ(c.width(), 10);
    EXPECT_EQ(c.height(), 20);
    for (int x = 0; x < c.width(); ++x)
    {
        for (int y = 0; y < c.height(); ++y)
        {
            EXPECT_EQ(c.pixel(x, y), dito::util::Color(0, 0, 0));
        }
    }
}

TEST(Canvas, WritePixel)
{
    Canvas c(10, 20);
    dito::util::Color red(1, 0, 1);
    c.set_pixel(2, 3, red);
    EXPECT_EQ(c.pixel(2, 3), red);
}

TEST(Canvas, PPMHeader)
{
    Canvas c(5, 3);
    std::string ppm = c.to_ppm();
    EXPECT_TRUE(ppm.rfind("P3\n5 3\n255\n") == 0);
    auto lines = string_to_lines(ppm);
    EXPECT_EQ(lines[0], "P3");
    EXPECT_EQ(lines[1], "5 3");
    EXPECT_EQ(lines[2], "255");
}

TEST(Canvas, PPMBody)
{
    Canvas c(5, 3);
    dito::util::Color c1(1.5, 0, 0);
    dito::util::Color c2(0, 0.5, 0);
    dito::util::Color c3(-0.5, 0, 1);
    c.set_pixel(0, 0, c1);
    c.set_pixel(2, 1, c2);
    c.set_pixel(4, 2, c3);
    std::string ppm = c.to_ppm();
    auto lines = string_to_lines(ppm);
    EXPECT_EQ(lines[3], "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0");
    EXPECT_EQ(lines[4], "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0");
    EXPECT_EQ(lines[5], "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255");
}
