#include <gtest/gtest.h>

#include "color.hpp"

using namespace dito::util;

TEST(Color, Initializer)
{
    Color c(-0.5, 0.4, 1.7);
    EXPECT_EQ(-0.5, c.red());
    EXPECT_EQ(0.4, c.green());
    EXPECT_EQ(1.7, c.blue());
}

TEST(Color, Equal)
{
    Color c1(-0.5, 0.4, 1.7);
    Color c2(-0.5, 0.4, 1.7);
    EXPECT_EQ(c1, c2);
}

TEST(Color, NotEqual)
{
    Color c1(-0.5, 0.4, 1.3);
    Color c2(-0.5, 0.4, 1.7);
    EXPECT_NE(c1, c2);
}

TEST(Color, Add)
{
    Color c1(0.9, 0.6, 0.75);
    Color c2(0.7, 0.1, 0.25);
    EXPECT_EQ(c1 + c2, Color(1.6, 0.7, 1.0));
}

TEST(Color, Sub)
{
    Color c1(0.9, 0.6, 0.75);
    Color c2(0.7, 0.1, 0.25);
    EXPECT_EQ(c1 - c2, Color(0.2, 0.5, 0.5));
}

TEST(Color, Mult)
{
    Color c(0.2, 0.3 , 0.4);
    EXPECT_EQ(c * 2, Color(0.4, 0.6, 0.8));
}

TEST(Color, MultTwoColor)
{
    Color c1(1, 0.2, 0.4);
    Color c2(0.9, 1, 0.1);
    EXPECT_EQ(c1 * c2, Color(0.9, 0.2, 0.04));
}
