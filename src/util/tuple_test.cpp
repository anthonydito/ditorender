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