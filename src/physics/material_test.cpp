#include <gtest/gtest.h>

#include "material.hpp"

using namespace dito::physics;
using namespace dito::util;

TEST(Material, MaterialInitializer)
{
    Material m;
    EXPECT_EQ(m.color(), Color(1, 1, 1));
    EXPECT_EQ(m.ambient(), 0.1);
    EXPECT_EQ(m.diffuse(), 0.9);
    EXPECT_EQ(m.specular(), 0.9);
    EXPECT_EQ(m.shininess(), 200);
}