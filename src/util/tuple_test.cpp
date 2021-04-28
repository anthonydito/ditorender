#include <gtest/gtest.h>

#include "tuple.hpp"

TEST(Tuples, EqualityTrue) {
    auto t1 = dito::util::point(5.2, 3.2, 54.0);
    auto t2 = dito::util::point(5.2, 3.2, 54.0);
    EXPECT_TRUE(t1 == t2);
}

TEST(Tuples, EqualityFalse) {
    auto t1 = dito::util::point(5.2, 3.2, 54.0);
    auto t2 = dito::util::point(5.2, 3.2, 54.001);
    EXPECT_FALSE(t1 == t2);
}

TEST(Tuples, CreatePoint) {
    auto a = dito::util::point(4, -4, 3);
    EXPECT_DOUBLE_EQ(a[0], 4);
    EXPECT_DOUBLE_EQ(a[1], -4);
    EXPECT_DOUBLE_EQ(a[2], 3);
    EXPECT_DOUBLE_EQ(a[3], 0);
}

TEST(Tuples, CreateVector) {
    auto a = dito::util::vector(4, -4, 3);
    EXPECT_DOUBLE_EQ(a[0], 4);
    EXPECT_DOUBLE_EQ(a[1], -4);
    EXPECT_DOUBLE_EQ(a[2], 3);
    EXPECT_DOUBLE_EQ(a[3], 1);
}
