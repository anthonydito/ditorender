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

// TEST(Color, Add)
// {
//     Color c1(0.9, 0.6, 0.75);
//     Colr
// }
