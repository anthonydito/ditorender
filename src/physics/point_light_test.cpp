#include <gtest/gtest.h>

#include "point_light.hpp"

using namespace dito::physics;
using namespace dito::util;

TEST(PointLight, CreatePointLight)
{

    Color intensity(1, 1, 1);
    Point position(0, 0, 0);

    PointLight light(position, intensity);

    PointLight pl(position, intensity);

    EXPECT_EQ(pl.position(), position);
    EXPECT_EQ(pl.intensity(), intensity);
}