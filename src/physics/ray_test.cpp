#include <gtest/gtest.h>

#include "ray.hpp"
#include "../util/point.hpp"
#include "../util/vector.hpp"
#include "intersection.hpp"
#include "intersections.hpp"
#include "world.hpp"

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
    auto s = std::make_shared<Sphere>();
    auto xs = r.intersets(s);
    EXPECT_EQ(xs.size(), 2);
    EXPECT_EQ(xs[0].t(), 4.0);
    EXPECT_EQ(xs[1].t(), 6.0);
}

TEST(Ray, IntersectAtTangent)
{
    Ray r = Ray(Point(0, 1, -5), Vector(0, 0, 1));
    auto s = std::make_shared<Sphere>();
    auto xs = r.intersets(s);
    EXPECT_EQ(xs.size(), 2);
    EXPECT_EQ(xs[0].t(), 5.0);
    EXPECT_EQ(xs[1].t(), 5.0);
}

TEST(Ray, RayMissesSphere)
{
    Ray r = Ray(Point(0, 2, -5), Vector(0, 0, 1));
    auto s = std::make_shared<Sphere>();
    auto xs = r.intersets(s);
    EXPECT_EQ(xs.size(), 0);
}

TEST(Ray, RayStartsInSphere)
{
    Ray r = Ray(Point(0, 0, 0), Vector(0, 0, 1));
    auto s = std::make_shared<Sphere>();
    auto xs = r.intersets(s);
    EXPECT_EQ(xs.size(), 2);
    EXPECT_EQ(xs[0].t(), -1.0);
    EXPECT_EQ(xs[1].t(), 1.0);
}

TEST(Ray, RayInFrontOfSphere)
{
    Ray r = Ray(Point(0, 0, 5), Vector(0, 0, 1));
    auto s = std::make_shared<Sphere>();
    auto xs = r.intersets(s);
    EXPECT_EQ(xs.size(), 2);
    EXPECT_EQ(xs[0].t(), -6.0);
    EXPECT_EQ(xs[1].t(), -4.0);
}

TEST(Ray, IntersectionEncapsulatesData)
{
    auto s = std::make_shared<Sphere>();
    Intersection i(3.5, s);
    EXPECT_EQ(i.t(), 3.5);
    EXPECT_EQ(i.object(), s);
}

TEST(Ray, AggregatingIntersections)
{
    auto sphere = std::make_shared<Sphere>();
    auto other = std::make_shared<Sphere>();
    Intersection i1(1, sphere);
    Intersection i2(2, sphere);
    Intersections xs({i1, i2});
    EXPECT_EQ(xs.size(), 2);
    EXPECT_EQ(xs.items()[0].object(), sphere);
    EXPECT_NE(xs.items()[0].object(), other);
    EXPECT_EQ(xs.items()[1].object(), sphere);
}

TEST(Ray, HitAllPositive)
{
    auto s = std::make_shared<Sphere>();
    Intersection i1(1, s);
    Intersection i2(2, s);
    Intersections xs({i1, i2});
    auto i = xs.hit();
    EXPECT_EQ(i1, i);
}

TEST(Ray, HitSomeNegative)
{
    auto s = std::make_shared<Sphere>();
    Intersection i1(-1, s);
    Intersection i2(1, s);
    Intersections xs({i2, i1});
    auto i = xs.hit();
    EXPECT_EQ(i2, i);
}

TEST(Ray, HitAllNegative)
{
    auto s = std::make_shared<Sphere>();
    Intersection i1(-1, s);
    Intersection i2(-2, s);
    Intersections xs({i1, i2});
    auto i = xs.hit();
    EXPECT_FALSE(i.has_value());
}

TEST(Ray, HitIsAlwaysNonNegativeIntersection)
{
    auto s = std::make_shared<Sphere>();
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

TEST(Ray, ScaledSphereWithRay)
{
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    auto s = std::make_shared<Sphere>();
    s->set_transform(Matrix::scaling(2, 2, 2));
    Intersections xs = r.intersets(s);
    EXPECT_EQ(xs.size(), 2);
    EXPECT_EQ(xs[0].t(), 3);
    EXPECT_EQ(xs[1].t(), 7);
}

TEST(Ray, ScaledSphereWithTranslated)
{
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    auto s = std::make_shared<Sphere>();
    s->set_transform(Matrix::translation(5, 0, 0));
    Intersections xs = r.intersets(s);
    EXPECT_EQ(xs.size(), 0);
}

TEST(Ray, IntersectionWithDefaultWorld)
{
    World w = World::default_world();
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    auto xs = r.intersects(w);
    EXPECT_EQ(xs.size(), 4);
    EXPECT_EQ(xs[0].t(), 4);
    EXPECT_EQ(xs[1].t(), 4.5);
    EXPECT_EQ(xs[2].t(), 5.5);
    EXPECT_EQ(xs[3].t(), 6);
}

TEST(Ray, PrecomputingState)
{
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    auto s = std::make_shared<Sphere>();
    Intersection i(4.0, s);
    auto comps = r.prepare_computations(i);
    EXPECT_EQ(comps.t(), i.t());
    EXPECT_EQ(comps.object(), i.object());
    EXPECT_EQ(comps.point(), Point(0, 0, -1));
    EXPECT_EQ(comps.eye_vector(), Vector(0, 0, -1));
    EXPECT_EQ(comps.normal_vector(), Vector(0, 0, -1));
}

TEST(Ray, ComputationsWhenHitOccursOnOutside)
{
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    auto s = std::make_shared<Sphere>();
    Intersection i(4.0, s);
    auto comps = r.prepare_computations(i);
    EXPECT_FALSE(comps.inside());
}

TEST(Ray, ComputationsWhenHitOccursOnInside)
{
    Ray r(Point(0, 0, 0), Vector(0, 0, 1));
    auto s = std::make_shared<Sphere>();
    Intersection i(1, s);
    auto comps = r.prepare_computations(i);
    EXPECT_EQ(Point(0, 0, 1), comps.point());
    EXPECT_EQ(comps.eye_vector(), Vector(0, 0, -1));
    EXPECT_TRUE(comps.inside());
    EXPECT_EQ(comps.normal_vector(), Vector(0, 0, -1));
}

TEST(Ray, ShadingAnIntersection)
{
    World w = World::default_world();
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    auto s = w.objects()[0];
    Intersection i = Intersection(4, s);
    auto comps = r.prepare_computations(i);
    Color c = w.shade_hit(comps);

    EXPECT_EQ(c, Color(0.38066, 0.47583, 0.2855));
}

TEST(Ray, ShadingAnIntersectionFromInside)
{
    World w = World::default_world();
    w.set_light(PointLight(Point(0, 0.25, 0), Color(1, 1, 1)));
    Ray r = Ray(Point(0, 0, 0), Vector(0, 0, 1));
    auto shape = w.objects()[1];
    Intersection i(0.5, shape);
    auto comps = r.prepare_computations(i);
    auto c = w.shade_hit(comps);
    EXPECT_EQ(c, Color(0.90498, 0.90498, 0.90498));
}

TEST(Ray, ColorWhenARayMisses)
{
    World w = World::default_world();
    Ray r = Ray(Point(0, 0, -5), Vector(0, 1, 0));
    Color c = r.color_at(w);
    EXPECT_EQ(c, Color(0, 0, 0));
}

TEST(Ray, ColorWhenARayHits)
{
    World w = World::default_world();
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    Color c = r.color_at(w);
    EXPECT_EQ(c, Color(0.38066, 0.47583, 0.2855));
}
