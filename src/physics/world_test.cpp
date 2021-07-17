#include <gtest/gtest.h>

#include <optional>
#include "world.hpp"
#include "../util/color.hpp"
#include "../util/point.hpp"
#include "../physics/ray.hpp"
#include "../physics/point_light.hpp"

using namespace dito::physics;
using namespace dito::util;

TEST(World, TestEmpty)
{
    World w;
    EXPECT_EQ(w.objects().size(), 0);
    EXPECT_EQ(w.lights().size(), 0);
}

TEST(World, TestDefault)
{
    World w = World::default_world();
    PointLight pl = *w.light();
    EXPECT_EQ(pl, PointLight(Point(-10, 10, -10), Color(1, 1, 1)));
    EXPECT_EQ(w.objects().size(), 2);
}