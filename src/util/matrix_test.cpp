#include <gtest/gtest.h>

#include "matrix.hpp"

using namespace dito::util;

TEST(Matrix, Indices)
{
    Matrix m{
        {1, 2, 3, 4},
        {5.5, 6.5, 7.5, 8.5},
        {9, 10, 11, 12},
        {13.5, 14.5, 15.5, 16.5}};
    EXPECT_EQ(m.get(0, 0), 1);
    EXPECT_EQ(m.get(0, 3), 4);
    EXPECT_EQ(m.get(1, 0), 5.5);
    EXPECT_EQ(m.get(1, 2), 7.5);
    EXPECT_EQ(m.get(2, 2), 11);
    EXPECT_EQ(m.get(3, 0), 13.5);
    EXPECT_EQ(m.get(3, 2), 15.5);
}

TEST(Matrix, 2x2MatrixIndices)
{
    Matrix m{
        {-3, 5},
        {1, -2}};
    EXPECT_EQ(m.get(0, 0), -3);
    EXPECT_EQ(m.get(0, 1), 5);
    EXPECT_EQ(m.get(1, 0), 1);
    EXPECT_EQ(m.get(1, 1), -2);
}

TEST(Matrix, 3x3MatrixIndices)
{
    Matrix m{
        {-3, 5, 0},
        {1, -2, -7},
        {0, 1, 1}};
    EXPECT_EQ(m.get(0, 0), -3);
    EXPECT_EQ(m.get(1, 1), -2);
    EXPECT_EQ(m.get(2, 2), 1);
}

TEST(Matrix, 4z4MatrixEqual)
{
    Matrix a{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 15}};
    Matrix b{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 15}};
    EXPECT_EQ(a, b);
}

TEST(Matrix, 4z4MatrixNotEqual)
{
    Matrix a{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 15}};
    Matrix b{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    EXPECT_NE(a, b);
}

TEST(Matrix, Multiply1)
{
    Matrix a{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 8, 7, 6},
        {5, 4, 3, 2}
    };
    Matrix b{
        {-2, 1, 2, 3},
        {3, 2, 1, -1},
        {4, 3, 6, 5},
        {1, 2, 7, 8}
    };
    Matrix expected{
        {20, 22, 50, 48},
        {44, 54, 114, 108},
        {40, 58, 110, 102},
        {16, 26, 46, 42}
    };
    Matrix multiplied = a * b;
    EXPECT_EQ(multiplied.get(0, 0), 20);
    EXPECT_EQ(multiplied, expected);
}
