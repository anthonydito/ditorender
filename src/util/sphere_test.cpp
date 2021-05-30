#include <gtest/gtest.h>

#include "sphere.hpp"
#include "matrix.hpp"

using namespace dito::util;

TEST(Sphere, DefaultTransformation)
{
    Sphere s;
    EXPECT_EQ(s.transform(), Matrix::identity_matrix(4));
}

TEST(Sphere, RotationTransformation)
{
    Sphere s;
    Matrix translation = Matrix::translation(2, 3, 4);
    s.set_transform(translation);
    EXPECT_EQ(s.transform(), translation);
}
