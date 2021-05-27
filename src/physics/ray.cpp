#include "ray.hpp"

using namespace dito::util;
using namespace dito::physics;

Ray::Ray(Point origin, Vector direction)
{
    this->_origin = origin;
    this->_direction = direction;
}

Point Ray::origin() const 
{
    return this->_origin;
}

Vector Ray::direction() const
{
    return this->_direction;
}

Point Ray::position(double time) const
{
    return this->origin() + (this->direction() * time);
}

std::vector<double> Ray::intersets(Sphere sphere) const
{
    std::vector<double> intersection_points;

    Tuple sphere_to_ray = this->origin() - sphere.origin();
    auto a = this->direction().dot(this->direction());
    auto b = 2 * this->direction().dot(sphere_to_ray);
    auto c = sphere_to_ray.dot(sphere_to_ray) - 1;

    auto discriminant = pow(b, 2) - (4 * a * c);

    if (discriminant < 0)
    {
        // No intersection points
        return intersection_points;
    }

    auto sqrt_discriminant = sqrt(discriminant);

    auto t1 = (-b - sqrt_discriminant) / (2 * a);
    auto t2 = (-b + sqrt_discriminant) / (2 * a);

    intersection_points.push_back(t1);
    intersection_points.push_back(t2);

    return intersection_points;
}
