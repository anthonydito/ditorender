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

TEST(Matrix, MultiplyTuple)
{
    Matrix a{
        {1, 2, 3, 4},
        {2, 4, 4, 2},
        {8, 6, 4, 1},
        {0, 0, 0, 1}
    };
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
        {4, 8, 16, 32}
    };
    Matrix identity_matrix = Matrix::identity_matrix(4);
    EXPECT_EQ(m * identity_matrix, m);
}

TEST(Matrix, Transpose)
{
    Matrix m{
        {0, 9, 3, 0},
        {9, 8, 0, 8},
        {1, 8, 5, 3},
        {0, 0, 5, 8}
    };
    Matrix transposed{
        {0, 9, 1, 0},
        {9, 8, 8, 0},
        {3, 0, 5, 5},
        {0, 8, 3, 8}
    };
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
        {-3, 2}
    };
    EXPECT_EQ(m.determinant(), 17);
}

TEST(Matrix, Submatrix1)
{
    Matrix a{
        {1, 5, 0},
        {-3, 2, 7},
        {0, 6, -3}
    };
    Matrix expected{
        {-3, 2},
        {0, 6}
    }; 
    EXPECT_EQ(a.submatrix(0, 2), expected);
}

TEST(Matrix, Submatrix2)
{
    Matrix m = {
        {-6, 1, 1, 6},
        {-8, 5, 8, 6},
        {-1, 0, 8, 2},
        {-7, 1, -1, 1}
    };
    Matrix expected{
        {-6, 1, 6},
        {-8, 8, 6},
        {-7, -1, 1}
    };
    EXPECT_EQ(m.submatrix(2, 1), expected);
}
