#include <gtest/gtest.h>

#include "tuple.hpp"

using namespace dito;

TEST(Tuples, EqualityTrue)
{
    auto t1 = util::create_point(5.2, 3.2, 54.0);
    auto t2 = util::create_point(5.2, 3.2, 54.0);
    EXPECT_TRUE(util::tuple_equal(t1, t2));
}

TEST(Tuples, EqualityFalse)
{
    auto t1 = util::create_point(5.2, 3.2, 54.0);
    auto t2 = util::create_point(5.2, 3.2, 54.001);
    EXPECT_FALSE(util::tuple_equal(t1, t2));
}

TEST(Tuples, CreatePoint)
{
    auto a = util::create_point(4, -4, 3);
    EXPECT_DOUBLE_EQ(a[0], 4);
    EXPECT_DOUBLE_EQ(a[1], -4);
    EXPECT_DOUBLE_EQ(a[2], 3);
    EXPECT_DOUBLE_EQ(a[3], 1);
}

TEST(Tuples, CreateVector)
{
    auto a = util::create_vector(4, -4, 3);
    EXPECT_DOUBLE_EQ(a[0], 4);
    EXPECT_DOUBLE_EQ(a[1], -4);
    EXPECT_DOUBLE_EQ(a[2], 3);
    EXPECT_DOUBLE_EQ(a[3], 0);
}

TEST(Tuples, AddTuples)
{
    auto a1 = util::create_point(3, -2, 5);
    auto a2 = util::create_vector(-2, 3, 1);
    auto expected = util::create_point(1, 1, 6);
    auto add_output = util::tuple_add(a1, a2);
    EXPECT_TRUE(util::tuple_equal(expected, add_output));
}

TEST(Tuples, SubtractTwoPoints)
{
    auto p1 = util::create_point(3, 2, 1);
    auto p2 = util::create_point(5, 6, 7);
    auto expected = util::create_vector(-2, -4, -6);
    EXPECT_TRUE(util::tuple_equal(util::tuple_sub(p1, p2), expected));
}

TEST(Tuples, SubtractVectorFromPoint)
{
    auto p = util::create_point(3, 2, 1);
    auto v = util::create_vector(5, 6, 7);
    auto expected = util::create_point(-2, -4, -6);
    EXPECT_TRUE(util::tuple_equal(util::tuple_sub(p, v), expected));
}

TEST(Tuples, SubtractTwoVectors)
{
    auto v1 = util::create_vector(3, 2, 1);
    auto v2 = util::create_vector(5, 6, 7);
    auto expected = util::create_vector(-2, -4, -6);
    EXPECT_TRUE(util::tuple_equal(util::tuple_sub(v1, v2), expected));
}

TEST(Tuples, SubtractZeroVector)
{
    auto zero = util::create_vector(0, 0, 0);
    auto v = util::create_vector(1, -2, 3);
    auto expected = util::create_vector(-1, 2, -3);
    EXPECT_TRUE(util::tuple_equal(util::tuple_sub(zero, v), expected));
}

TEST(Tuples, NegateTuple)
{
    util::tuple v = util::tuple{1, -2, 3, -4};
    util::tuple expected = util::tuple{-1, 2, -3, 4};
    EXPECT_TRUE(util::tuple_equal(util::tuple_negate(v), expected));
}

TEST(Tuples, Multiply1)
{
    util::tuple a = util::tuple{1, -2, 3, -4};
    util::tuple expected = util::tuple{3.5, -7, 10.5, -14};
    EXPECT_TRUE(util::tuple_equal(util::tuple_multiply(a, 3.5), expected));
}

TEST(Tuples, Multiply2)
{
    util::tuple a = util::tuple{1, -2, 3, -4};
    util::tuple expected = util::tuple{0.5, -1, 1.5, -2};
    EXPECT_TRUE(util::tuple_equal(util::tuple_multiply(a, 0.5), expected));
}

TEST(Tuples, Divide)
{
    util::tuple a = util::tuple{1, -2, 3, -4};
    util::tuple expected = util::tuple{0.5, -1, 1.5, -2};
    EXPECT_TRUE(util::tuple_equal(util::tuple_divide(a, 2), expected));
}

TEST(Tuples, Magnitude1)
{
    auto v = util::create_vector(1, 0, 0);
    EXPECT_EQ(util::tuple_magnitude(v), 1);
}

TEST(Tuples, Magnitude2)
{
    auto v = util::create_vector(0, 1, 0);
    EXPECT_EQ(util::tuple_magnitude(v), 1);
}

TEST(Tuples, Magnitude3)
{
    auto v = util::create_vector(0, 0, 1);
    EXPECT_EQ(util::tuple_magnitude(v), 1);
}

TEST(Tuples, Magnitude4)
{
    auto v = util::create_vector(0, 0, 1);
    EXPECT_EQ(util::tuple_magnitude(v), 1);
}

TEST(Tuples, Magnitude5)
{
    auto v = util::create_vector(0, 0, 1);
    EXPECT_EQ(util::tuple_magnitude(v), 1);
}

TEST(Tuples, Magnitude6)
{
    auto v = util::create_vector(1, 2, 3);
    EXPECT_EQ(util::tuple_magnitude(v), sqrt(14));
}

TEST(Tuples, Magnitude7)
{
    auto v = util::create_vector(-1, -2, -3);
    EXPECT_EQ(util::tuple_magnitude(v), sqrt(14));
}

TEST(Tuples, Normalize1)
{
    auto v = util::create_vector(4, 0, 0);
    EXPECT_EQ(util::tuple_magnitude(v), 4);
    auto expected = util::create_vector(1, 0, 0);
    EXPECT_TRUE(
        util::tuple_equal(util::tuple_normalize(v),
                          expected));
}

TEST(Tuples, Normalize2)
{
    auto v = util::create_vector(1, 2, 3);
    auto expected = util::create_vector(0.26726, 0.53452, 0.80178);
    auto normalized = util::tuple_normalize(v);
    EXPECT_NEAR(
        normalized[0], 0.26726, .0001);
    EXPECT_NEAR(normalized[1], 0.53452, .0001);
    EXPECT_NEAR(normalized[2], 0.80178, .0001);
    EXPECT_NEAR(util::tuple_magnitude(normalized), 1, .0001);
}

