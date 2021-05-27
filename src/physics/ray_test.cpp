#include <gtest/gtest.h>

#include "ray.hpp"
#include "../util/point.hpp"
#include "../util/vector.hpp"
#include "intersection.hpp"
#include "intersections.hpp"

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

TEST(Ray, InsersectRayAtTwoPoints)
{
    Ray r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
    Sphere s = Sphere();
    auto xs = r.intersets(s);
    EXPECT_EQ(xs.size(), 2);
    EXPECT_EQ(xs[0].t(), 4.0);
    EXPECT_EQ(xs[1].t(), 6.0);
}

TEST(Ray, IntersectAtTangent)
{
    Ray r = Ray(Point(0, 1, -5), Vector(0, 0, 1));
    Sphere s = Sphere();
    auto xs = r.intersets(s);
    EXPECT_EQ(xs.size(), 2);
    EXPECT_EQ(xs[0].t(), 5.0);
    EXPECT_EQ(xs[1].t(), 5.0);
}

TEST(Ray, RayMissesSphere)
{
    Ray r = Ray(Point(0, 2, -5), Vector(0, 0, 1));
    Sphere s = Sphere();
    auto xs = r.intersets(s);
    EXPECT_EQ(xs.size(), 0);
}

TEST(Ray, RayStartsInSphere)
{
    Ray r = Ray(Point(0, 0, 0), Vector(0, 0, 1));
    Sphere s = Sphere();
    auto xs = r.intersets(s);
    EXPECT_EQ(xs.size(), 2);
    EXPECT_EQ(xs[0].t(), -1.0);
    EXPECT_EQ(xs[1].t(), 1.0);
}

TEST(Ray, RayInFrontOfSphere)
{
    Ray r = Ray(Point(0, 0, 5), Vector(0, 0, 1));
    Sphere s = Sphere();
    auto xs = r.intersets(s);
    EXPECT_EQ(xs.size(), 2);
    EXPECT_EQ(xs[0].t(), -6.0);
    EXPECT_EQ(xs[1].t(), -4.0);
}

TEST(Ray, IntersectionEncapsulatesData)
{
    Sphere s = Sphere();
    Intersection i(3.5, s);
    EXPECT_EQ(i.t(), 3.5);
    EXPECT_EQ(i.object(), s);
}

TEST(Ray, AggregatingIntersections)
{
    Sphere s = Sphere();
    Sphere other = Sphere();
    Intersection i1(1, s);
    Intersection i2(2, s);
    Intersections xs({i1, i2});
    EXPECT_EQ(xs.size(), 2);
    EXPECT_EQ(xs.items()[0].object(), s);
    EXPECT_NE(xs.items()[0].object(), other);
    EXPECT_EQ(xs.items()[1].object(), s);
}
