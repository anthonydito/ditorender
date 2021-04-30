#include <gtest/gtest.h>

#include "tuple.hpp"
#include "vector.hpp"
#include "point.hpp"

using namespace dito::util;

TEST(Tuples, EqualityTrue)
{
    Point p1(5.2, 3.2, 54.0);
    Point p2(5.2, 3.2, 54.0);
    EXPECT_TRUE(p1 == p2);
}

TEST(Tuples, EqualityFalse)
{
    Point p1(5.2, 3.2, 54.0);
    Point p2(5.2, 3.2, 54.001);
    EXPECT_FALSE(p1 == p2);
}

TEST(Tuples, EqualityTest2)
{
    Vector v1(-1, 2, -3);
    Vector v2(-1, 2, -3);
    EXPECT_TRUE(v1 == v2);
}

TEST(Tuples, CreatePoint)
{
    Point p(4, -4, 3);
    EXPECT_DOUBLE_EQ(p.x(), 4);
    EXPECT_DOUBLE_EQ(p.y(), -4);
    EXPECT_DOUBLE_EQ(p.z(), 3);
    EXPECT_DOUBLE_EQ(p.w(), 1);
}

TEST(Tuples, CreateVector)
{
    Vector p(4, -4, 3);
    EXPECT_DOUBLE_EQ(p.x(), 4);
    EXPECT_DOUBLE_EQ(p.y(), -4);
    EXPECT_DOUBLE_EQ(p.z(), 3);
    EXPECT_DOUBLE_EQ(p.w(), 0);
}

TEST(Tuples, AddTuples)
{
    
    Point a1(3, -2, 5);
    Vector a2(-2, 3, 1);
    Point expected(1, 1, 6);
    auto add_output = a1 + a2;
    EXPECT_TRUE(add_output.eq(expected));
}

TEST(Tuples, SubtractTwoPoints)
{
    Point p1(3, 2, 1);
    Point p2(5, 6, 7);
    Vector expected(-2, -4, -6);
    EXPECT_TRUE(expected.eq(p1.sub(p2)));
}

TEST(Tuples, SubtractVectorFromPoint)
{
    Point p(3, 2, 1);
    Vector v(5, 6, 7);
    Point expected(-2, -4, -6);
    EXPECT_TRUE(expected.eq(p - v));
}

TEST(Tuples, SubtractTwoVectors)
{
    Vector v1(3, 2, 1);
    Vector v2(5, 6, 7);
    Vector expected(-2, -4, -6);
    auto output = v1.sub(v2);
    EXPECT_DOUBLE_EQ(output.x(), -2);
    EXPECT_DOUBLE_EQ(output.y(), -4);
    EXPECT_DOUBLE_EQ(output.z(), -6);
    EXPECT_TRUE(expected.eq(v1.sub(v2)));
}

TEST(Tuples, SubtractZeroVector)
{
    Vector zero(0, 0, 0);
    Vector v(1, -2, 3);
    Vector expected(-1, 2, -3);
    auto output = zero.sub(v);
    EXPECT_DOUBLE_EQ(output.x(), -1);
    EXPECT_DOUBLE_EQ(output.y(), 2);
    EXPECT_DOUBLE_EQ(output.z(), -3);
    EXPECT_TRUE(expected.eq(output));
}

TEST(Tuples, NegateTuple)
{
    Tuple t(1, -2, 3, -4);
    Tuple expected(-1, 2, -3, 4);
    EXPECT_TRUE(t.negate().eq(expected));
}

TEST(Tuples, Multiply1)
{
    Tuple a(1, -2, 3, -4);
    Tuple expected(3.5, -7, 10.5, -14);
    EXPECT_TRUE(a.multiply(3.5).eq(expected));
}

TEST(Tuples, Multiply2)
{
    Tuple a(1, -2, 3, -4);
    Tuple expected(0.5, -1, 1.5, -2);
    EXPECT_TRUE(a.multiply(0.5).eq(expected));
}

TEST(Tuples, Divide)
{
    Tuple a(1, -2, 3, -4);
    Tuple expected(0.5, -1, 1.5, -2);
    EXPECT_TRUE(a.divide(2).eq(expected));
}

TEST(Tuples, Magnitude1)
{
    Vector v(1, 0, 0);
    EXPECT_EQ(v.magnitude(), 1);
}

TEST(Tuples, Magnitude2)
{
    Vector v(0, 1, 0);
    EXPECT_EQ(v.magnitude(), 1);
}

TEST(Tuples, Magnitude3)
{
    Vector v(0, 0, 1);
    EXPECT_EQ(v.magnitude(), 1);
}

TEST(Tuples, Magnitude6)
{
    Vector v(1, 2, 3);
    EXPECT_EQ(v.magnitude(), sqrt(14));
}

TEST(Tuples, Magnitude7)
{
    Vector v(-1, -2, -3);
    EXPECT_EQ(v.magnitude(), sqrt(14));
}

TEST(Tuples, Normalize1)
{
    Vector v(4, 0, 0);
    EXPECT_EQ(v.magnitude(), 4);
    Vector expected(1, 0, 0);
    EXPECT_TRUE(v.normalize().eq(expected));
}

TEST(Tuples, Normalize2)
{
    Vector v(1, 2, 3);
    Vector expected(0.26726, 0.53452, 0.80178);
    auto normalized = v.normalize();
    EXPECT_NEAR(
        normalized.x(), 0.26726, .0001);
    EXPECT_NEAR(normalized.y(), 0.53452, .0001);
    EXPECT_NEAR(normalized.z(), 0.80178, .0001);
    EXPECT_NEAR(normalized.magnitude(), 1, .0001);
}

TEST(Tuples, Dot)
{
    Vector a(1, 2, 3);
    Vector b(2, 3, 4);
    EXPECT_EQ(a.dot(b), 20);
}

TEST(Tuples, Cross)
{
    Vector a(1, 2, 3);
    Vector b(2, 3, 4);
    auto cross1 = a.cross(b);
    auto cross2 = b.cross(a);
    EXPECT_TRUE(Vector(-1, 2, -1).eq(cross1));
    EXPECT_TRUE(Vector(1, -2, 1).eq(cross2));
}
