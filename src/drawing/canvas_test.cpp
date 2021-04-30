#include <gtest/gtest.h>

#include "canvas.hpp"

using namespace dito::drawing;

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


