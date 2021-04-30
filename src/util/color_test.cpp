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
