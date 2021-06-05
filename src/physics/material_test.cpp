#include <gtest/gtest.h>

#include "material.hpp"
#include "../util/vector.hpp"
#include "../util/point.hpp"

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

TEST(Material, LightingBetweenEyeAndSurface)
{
    Material m;
    Point position(0, 0, 0);
    Vector eye_vector = Vector(0, 0, -1);
    Vector normal_vector = Vector(0, 0, -1);
    PointLight point_light = PointLight(Point(0, 0, -10), Color(1, 1, 1));
    auto result = m.lighting(point_light, position, eye_vector, normal_vector);
    EXPECT_EQ(result, Color(1.9, 1.9, 1.9));
}

TEST(Material, LightingBetweenEyeAndSurface45)
{
    double sqrt_2_div_2 = sqrt(2) / 2;
    Material m;
    Point position(0, 0, 0);
    Vector eye_vector = Vector(0, sqrt_2_div_2, -sqrt_2_div_2);
    Vector normal_vector = Vector(0, 0, -1);
    PointLight point_light = PointLight(Point(0, 0, -10), Color(1, 1, 1));
    auto result = m.lighting(point_light, position, eye_vector, normal_vector);
    EXPECT_EQ(result, Color(1, 1, 1));
}

TEST(Material, LightingBetweenEyeAndSurfaceOffset45)
{
    Material m;
    Point position(0, 0, 0);
    Vector eye_vector = Vector(0, 0, -1);
    Vector normal_vector = Vector(0, 0, -1);
    PointLight point_light = PointLight(Point(0, 10, -10), Color(1, 1, 1));
    auto result = m.lighting(point_light, position, eye_vector, normal_vector);
    EXPECT_EQ(result, Color(0.7364, 0.7364, 0.7364));
}

TEST(Material, LightingWithEyeAtReflectionVector)
{
    double sqrt_2_div_2 = sqrt(2) / 2;
    Material m;
    Point position(0, 0, 0);
    Vector eye_vector = Vector(0, -sqrt_2_div_2, -sqrt_2_div_2);
    Vector normal_vector = Vector(0, 0, -1);
    PointLight point_light = PointLight(Point(0, 10, -10), Color(1, 1, 1));
    auto result = m.lighting(point_light, position, eye_vector, normal_vector);
    EXPECT_EQ(result, Color(1.6364, 1.6364, 1.6364));
}

TEST(Material, LightingWithLightBehindSurface)
{
    Material m;
    Point position(0, 0, 0);
    Vector eye_vector = Vector(0, 0, -1);
    Vector normal_vector = Vector(0, 0, -1);
    PointLight point_light = PointLight(Point(0, 0, 10), Color(1, 1, 1));
    auto result = m.lighting(point_light, position, eye_vector, normal_vector);
    EXPECT_EQ(result, Color(0.1, 0.1, 0.1));
}
