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

TEST(Ray, HitAllPositive)
{
    Sphere s;
    Intersection i1(1, s);
    Intersection i2(2, s);
    Intersections xs({i1, i2});
    auto i = xs.hit();
    EXPECT_EQ(i1, i);
}

TEST(Ray, HitSomeNegative)
{
    Sphere s;
    Intersection i1(-1, s);
    Intersection i2(1, s);
    Intersections xs({i2, i1});
    auto i = xs.hit();
    EXPECT_EQ(i2, i);
}

TEST(Ray, HitAllNegative)
{
    Sphere s;
    Intersection i1(-1, s);
    Intersection i2(-2, s);
    Intersections xs({i1, i2});
    auto i = xs.hit();
    EXPECT_FALSE(i.has_value());
}

TEST(Ray, HitIsAlwaysNonNegativeIntersection)
{
    Sphere s;
    Intersection i1(5, s);
    Intersection i2(7, s);
    Intersection i3(-3, s);
    Intersection i4(2, s);
    Intersections xs({i1, i2, i3, i4});
    auto i = xs.hit();
    EXPECT_TRUE(i.has_value());
    EXPECT_EQ(*i, i4);
}

TEST(Ray, TranslatingRay)
{
    Ray r(Point(1, 2, 3), Vector(0, 1, 0));
    Matrix m = Matrix::translation(3, 4, 5);
    Ray r2 = r.transform(m);
    EXPECT_EQ(r2.origin(), Point(4, 6, 8));
    EXPECT_EQ(r2.direction(), Vector(0, 1, 0));
}

TEST(Ray, ScalingRay)
{
    Ray r(Point(1, 2, 3), Vector(0, 1, 0));
    Matrix m = Matrix::scaling(2, 3, 4);
    Ray r2 = r.transform(m);
    EXPECT_EQ(r2.origin(), Point(2, 6, 12));
    EXPECT_EQ(r2.direction(), Vector(0, 3, 0));
}
