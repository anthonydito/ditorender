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

TEST(Sphere, NormalOfSphereOnXAxis)
{
    Sphere s;
    auto n = s.normal_at(Point(1, 0, 0));
    EXPECT_EQ(n, Vector(1, 0, 0));
}

TEST(Sphere, NormalOfSphereOfYAxis)
{
    Sphere s;
    auto n = s.normal_at(Point(0, 0, 1));
    EXPECT_EQ(n, Vector(0, 0, 1));
}

TEST(Sphere, NormalOfSphereOfZAxis)
{
    Sphere s;
    auto n = s.normal_at(Point(0, 0, 1));
    EXPECT_EQ(n, Vector(0, 0, 1));
}

TEST(Sphere, NormalOnNonAxial)
{
    Sphere s;
    double sqrt_3_divide_3 = sqrt(3) / 3;
    auto n = s.normal_at(Point(sqrt_3_divide_3, sqrt_3_divide_3, sqrt_3_divide_3));
    EXPECT_EQ(n, Vector(sqrt_3_divide_3, sqrt_3_divide_3, sqrt_3_divide_3));
}

TEST(Sphere, NormalIsANormalizedVector)
{
    Sphere s;
    double sqrt_3_divide_3 = sqrt(3) / 3;
    auto n = s.normal_at(Point(sqrt_3_divide_3, sqrt_3_divide_3, sqrt_3_divide_3));
    EXPECT_EQ(n, n.normalize());
}

TEST(Sphere, NormalOnTranslatedSphere)
{
    Sphere s;
    s.set_transform(Matrix::translation(0, 1, 0));
    auto n = s.normal_at(Point(0, 1.70711, -0.70711));
    EXPECT_EQ(n, Vector(0, 0.707107, -0.707107));
}

TEST(Sphere, NormalOnATransformedSphere)
{
    Sphere s;
    Matrix m = Matrix::scaling(1, 0.5, 1) * Matrix::rotation_z(M_PI / 5);
    s.set_transform(m);
    auto n = s.normal_at(Point(0, sqrt(2) / 2, -sqrt(2) / 2));
    EXPECT_EQ(n, Vector(0, 0.970143, -0.242536));
}
