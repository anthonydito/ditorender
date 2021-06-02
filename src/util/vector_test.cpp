#include <gtest/gtest.h>

#include "vector.hpp"

using namespace dito::util;

TEST(Vector, Reflect45Degrees)
{
    Vector v(1, -1, 0);
    Vector n(0, 1, 0);
    auto r = v.reflect(n);
    EXPECT_EQ(r, Vector(1, 1, 0));
}

TEST(Vector, ReflectSlantedSurface)
{
    Vector v(0, -1, 0);
    Vector n(sqrt(2) / 2, sqrt(2) / 2, 0);
    Vector r = v.reflect(n);
    EXPECT_EQ(r, Vector(1, 0, 0));
}
