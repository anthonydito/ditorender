#include "camera.hpp"

#include <math.h>
#include "../util/point.hpp"
#include "../util/vector.hpp"

using namespace dito::drawing;

Camera::Camera(int hsize, int vsize, double field_of_view) : Camera(hsize, vsize, field_of_view, dito::util::Matrix::identity_matrix(4))
{
}

Camera::Camera(int hsize, int vsize, double field_of_view, dito::util::Matrix transform) : _hsize(hsize), _vsize(vsize), _field_of_view(field_of_view), _transform(transform)
{
    this->_compute_and_store_pixel_size_and_half_width_height();
}

int Camera::hsize() const
{
    return this->_hsize;
}

int Camera::vsize() const
{
    return this->_vsize;
}

double Camera::field_of_view() const
{
    return this->_field_of_view;
}

dito::util::Matrix Camera::transform() const
{
    return this->_transform;
}

double Camera::pixel_size() const
{
    return this->_pixel_size;
}

double Camera::half_height() const
{
    return this->_half_height;
}

double Camera::half_width() const
{
    return this->_half_width;
}

void Camera::_compute_and_store_pixel_size_and_half_width_height()
{
    auto half_view = tan(this->field_of_view() / 2);
    double hsize_d = this->hsize();
    double vsize_d = this->vsize();
    auto aspect = hsize_d / vsize_d;
    double half_width;
    double half_height;
    if (aspect >= 1) {
        half_width = half_view;
        half_height = half_view / aspect;
    } else {
        half_width = half_view * aspect;
        half_height = half_view;
    }
    this->_pixel_size = (half_width * 2) / hsize_d;
    this->_half_height = half_height;
    this->_half_width = half_width;
}

dito::physics::Ray Camera::ray_for_pixel(int px, int py)
{
    auto half_width = this->half_width();
    auto half_height = this->half_height();
    auto pixel_size = this->pixel_size();
    auto px_double = static_cast<double>(px);
    auto py_double = static_cast<double>(py);
    auto xoffset = (px_double + 0.5) * pixel_size;
    auto yoffset = (py_double + 0.5) * pixel_size;

    auto worldx = half_width - xoffset;
    auto worldy = half_height - yoffset;

    auto pixel = this->transform().inverse() * dito::util::Point(worldx, worldy, -1);
    auto origin = this->transform().inverse() * dito::util::Point(0, 0, 0);
    dito::util::Vector direction = (pixel - origin).to_vector().normalize();

    dito::util::Point p = origin.to_point();

    return dito::physics::Ray(p, direction);
}