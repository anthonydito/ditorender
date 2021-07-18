#include <gtest/gtest.h>

#include <math.h>
#include "camera.hpp"
#include "../util/matrix.hpp"

using namespace dito::drawing;
using namespace dito::util;

TEST(Camera, ConstructingCamera)
{
    Camera c(160, 120, M_PI / 2);
    EXPECT_EQ(c.hsize(), 160);
    EXPECT_EQ(c.vsize(), 120);
    EXPECT_EQ(c.field_of_view(), M_PI / 2);
    Matrix identity = Matrix::identity_matrix(4);
    EXPECT_EQ(c.transform(), identity);
}

TEST(Camera, PixelSizeForHorizontalCamera)
{
    Camera c(200, 125, M_PI / 2);
    EXPECT_DOUBLE_EQ(c.pixel_size(), 0.01);
}

TEST(Camera, PixelSizeForVerticalCamera)
{
    Camera c(125, 200, M_PI / 2);
    EXPECT_DOUBLE_EQ(c.pixel_size(), 0.01);
}