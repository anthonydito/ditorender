#include <gtest/gtest.h>


#include "ray.hpp"
#include "../util/point.hpp"
#include "../util/vector.hpp"

using namespace dito::physics;
using namespace dito::util;

TEST(Ray, CreateRay)
{
    Point origin(1, 2, 3);
    Vector direction(4, 5, 6);

    Ray ray(origin, direction);
    EXPECT_EQ(ray.origin(), origin);
    EXPECT_EQ(ray.direction(), direction);
}

TEST(Ray, ComputePointFromDistance)
{
    Ray r(Point(2, 3, 4), Vector(1, 0, 0));
    EXPECT_EQ(r.position(0), Point(2, 3, 4));
    EXPECT_EQ(r.position(1), Point(3, 3, 4));
    EXPECT_EQ(r.position(-1), Point(1, 3, 4));
    EXPECT_EQ(r.position(2.5), Point(4.5, 3, 4));
}