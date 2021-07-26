#include <gtest/gtest.h>

#include <math.h>
#include "camera.hpp"
#include "../util/matrix.hpp"
#include "../physics/ray.hpp"

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

TEST(Camera, CameraThroughCenterOfCanvas)
{
    Camera c(201, 101, M_PI / 2);
    auto r = c.ray_for_pixel(100, 50);
    EXPECT_EQ(r.origin(), Point(0, 0, 0));
    EXPECT_EQ(r.direction(), Vector(0, 0, -1));
}

TEST(Camera, CameraThroughCornerOfCanvas)
{
    Camera c(201, 101, M_PI / 2);
    auto r = c.ray_for_pixel(0, 0);
    EXPECT_EQ(r.origin(), Point(0, 0, 0));
    EXPECT_EQ(r.direction(), Vector(0.665186, 0.332593, -0.668512));
}

TEST(Camera, CameraIsTransofrmed)
{
    dito::util::Matrix transform = Matrix::rotation_y(M_PI / 4) * Matrix::translation(0, -2, 5);
    Camera c(201, 101, M_PI / 2, transform);
    auto r = c.ray_for_pixel(100, 50);
    EXPECT_EQ(r.origin(), Point(0, 2, -5));
    EXPECT_EQ(r.direction(), Vector(sqrt(2) / 2, 0, -sqrt(2) / 2));
}
