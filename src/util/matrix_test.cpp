#include <gtest/gtest.h>

#include "matrix.hpp"
#include "tuple.hpp"

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
        {5, 4, 3, 2}};
    Matrix b{
        {-2, 1, 2, 3},
        {3, 2, 1, -1},
        {4, 3, 6, 5},
        {1, 2, 7, 8}};
    Matrix expected{
        {20, 22, 50, 48},
        {44, 54, 114, 108},
        {40, 58, 110, 102},
        {16, 26, 46, 42}};
    Matrix multiplied = a * b;
    EXPECT_EQ(multiplied.get(0, 0), 20);
    EXPECT_EQ(multiplied, expected);
}

TEST(Matrix, MultiplyTuple)
{
    Matrix a{
        {1, 2, 3, 4},
        {2, 4, 4, 2},
        {8, 6, 4, 1},
        {0, 0, 0, 1}};
    Tuple b(1, 2, 3, 1);
    Tuple expected(18, 24, 33, 1);
    EXPECT_EQ(a * b, expected);
}

TEST(Matrix, MultiplyByIdentityMatrix)
{
    Matrix m{
        {0, 1, 2, 4},
        {1, 2, 4, 8},
        {2, 4, 8, 16},
        {4, 8, 16, 32}};
    Matrix identity_matrix = Matrix::identity_matrix(4);
    EXPECT_EQ(m * identity_matrix, m);
}

TEST(Matrix, Transpose)
{
    Matrix m{
        {0, 9, 3, 0},
        {9, 8, 0, 8},
        {1, 8, 5, 3},
        {0, 0, 5, 8}};
    Matrix transposed{
        {0, 9, 1, 0},
        {9, 8, 8, 0},
        {3, 0, 5, 5},
        {0, 8, 3, 8}};
    EXPECT_EQ(m.transpose(), transposed);
}

TEST(Matrix, TranposeIdentity)
{
    Matrix m = Matrix::identity_matrix(4);
    EXPECT_EQ(m, m.transpose());
}

TEST(Matrix, Determinants)
{
    Matrix m{
        {1, 5},
        {-3, 2}};
    EXPECT_EQ(m.determinant(), 17);
}

TEST(Matrix, Submatrix1)
{
    Matrix a{
        {1, 5, 0},
        {-3, 2, 7},
        {0, 6, -3}};
    Matrix expected{
        {-3, 2},
        {0, 6}};
    EXPECT_EQ(a.submatrix(0, 2), expected);
}

TEST(Matrix, Submatrix2)
{
    Matrix m = {
        {-6, 1, 1, 6},
        {-8, 5, 8, 6},
        {-1, 0, 8, 2},
        {-7, 1, -1, 1}};
    Matrix expected{
        {-6, 1, 6},
        {-8, 8, 6},
        {-7, -1, 1}};
    EXPECT_EQ(m.submatrix(2, 1), expected);
}

TEST(Matrix, Minor)
{
    Matrix a{
        {3, 5, 0},
        {2, -1, -7},
        {6, -1, 5}};
    Matrix b = a.submatrix(1, 0);
    EXPECT_EQ(b.determinant(), 25);
    EXPECT_EQ(a.minor(1, 0), 25);
}

TEST(Matrix, Cofactor)
{
    Matrix a{
        {3, 5, 0},
        {2, -1, -7},
        {6, -1, 5}};
    EXPECT_EQ(a.minor(0, 0), -12);
    EXPECT_EQ(a.cofactor(0, 0), -12);
    EXPECT_EQ(a.minor(1, 0), 25);
    EXPECT_EQ(a.cofactor(1, 0), -25);
}

TEST(Matrix, Determinant3x3)
{
    Matrix a{
        {1, 2, 6},
        {-5, 8, -4},
        {2, 6, 4}};
    EXPECT_EQ(a.cofactor(0, 0), 56);
    EXPECT_EQ(a.cofactor(0, 1), 12);
    EXPECT_EQ(a.cofactor(0, 2), -46);
    EXPECT_EQ(a.determinant(), -196);
}

TEST(Matrix, Determinant4x4)
{
    Matrix a{
        {-2, -8, 3, 5},
        {-3, 1, 7, 3},
        {1, 2, -9, 6},
        {-6, 7, 7, -9}};
    EXPECT_EQ(a.cofactor(0, 0), 690);
    EXPECT_EQ(a.cofactor(0, 1), 447);
    EXPECT_EQ(a.cofactor(0, 2), 210);
    EXPECT_EQ(a.cofactor(0, 3), 51);
    EXPECT_EQ(a.determinant(), -4071);
}

TEST(Matrix, TestingAnInvertibleMatrixForInvertability1)
{
    Matrix a{
        {6, 4, 4, 4},
        {5, 5, 7, 6},
        {4, -9, 3, -7},
        {9, 1, 7, -6}};
    EXPECT_EQ(a.determinant(), -2120);
    EXPECT_TRUE(a.is_invertable());
}

TEST(Matrix, TestingAnInvertibleMatrixForInvertability2)
{
    Matrix a{
        {6, 4, 4, 4},
        {5, 5, 7, 6},
        {4, -9, 3, -7},
        {0, 0, 0, 0}};
    EXPECT_EQ(a.determinant(), 0);
    EXPECT_FALSE(a.is_invertable());
}

TEST(Matrix, CofactorMistakes)
{
    Matrix a{
        {-5, 2, 6, -8},
        {1, -5, 1, 8},
        {7, 7, -6, -7},
        {1, -3, 7, 4}};
    Matrix sub{
        {-5, 6, -8},
        {7, -6, -7},
        {1, 7, 4}};
    EXPECT_EQ(sub.determinant(), -775);
    EXPECT_EQ(a.minor(1, 1), -775);
    EXPECT_EQ(a.submatrix(1, 1), sub);
    EXPECT_EQ(a.cofactor(1, 1), -775);
}

TEST(Matrix, Inverse1)
{
    Matrix a{
        {-5, 2, 6, -8},
        {1, -5, 1, 8},
        {7, 7, -6, -7},
        {1, -3, 7, 4}};
    Matrix b = a.inverse();
    EXPECT_EQ(a.determinant(), 532);
    EXPECT_EQ(a.cofactor(2, 3), -160);
    EXPECT_EQ(b.get(3, 2), -160.0 / 532.0);
    EXPECT_EQ(a.cofactor(3, 2), 105);
    EXPECT_EQ(b.get(2, 3), 105.0 / 532.0);
    EXPECT_EQ(a.cofactor(1, 1), -775);
    EXPECT_EQ(a.cofactor(1, 3), -433);
    Matrix expected{
        {0.21805, 0.45113, 0.24060, -0.04511},
        {-0.80827, -1.45677, -0.44361, 0.52068},
        {-0.07895, -0.22368, -0.05263, 0.19737},
        {-0.52256, -0.81391, -0.30075, 0.30639}};
    EXPECT_EQ(expected, b);
}

TEST(Matrix, Inverse2)
{
    Matrix a{
        {8, -5, 9, 2},
        {7, 5, 6, 1},
        {-6, 0, 9, 6},
        {-3, 0, -9, -4}};
    Matrix expected{
        {-0.15385, -0.15385, -0.28205, -0.53846},
        {-0.07692, 0.12308, 0.02564, 0.03077},
        {0.35897, 0.35897, 0.43590, 0.92308},
        {-0.69231, -0.69231, -0.76923, -1.92308}};
    EXPECT_EQ(a.inverse(), expected);
}

TEST(Matrix, Inverse3)
{
    Matrix a{
        {9, 3, 0, 9},
        {-5, -2, -6, -3},
        {-4, 9, 6, 4},
        {-7, 6, 6, 2}};
    Matrix expected{
        {-0.04074, -0.07778, 0.14444, -0.22222},
        {-0.07778, 0.03333, 0.36667, -0.33333},
        {-0.02901, -0.14630, -0.10926, 0.12963},
        {0.17778, 0.06667, -0.26667, 0.33333}};
    EXPECT_EQ(a.inverse(), expected);
}
