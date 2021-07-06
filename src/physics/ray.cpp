#include "ray.hpp"

#include <algorithm>
#include "math.h"
#include "../util/tuple.hpp"
#include "intersection.hpp"

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

Intersections Ray::intersets(std::shared_ptr<Sphere> sphere) const
{

    Ray transform_ray = this->transform(sphere->transform().inverse());

    Intersections intersection_points;

    Tuple sphere_to_ray = transform_ray.origin() - sphere->origin();
    auto a = transform_ray.direction().dot(transform_ray.direction());
    auto b = 2 * transform_ray.direction().dot(sphere_to_ray);
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

    intersection_points.push_back(Intersection(t1, sphere));
    intersection_points.push_back(Intersection(t2, sphere));

    return intersection_points;
}

Intersections Ray::intersects(World &world) const
{

    std::vector<Intersection> all_intersections;

    for (auto sphere : world.objects()) {
        auto curr_intersections = this->intersets(sphere);
        for (auto intersection : curr_intersections.items()) {
            all_intersections.push_back(intersection);
        }
    }

    std::sort(all_intersections.begin(), all_intersections.end());

    return Intersections(all_intersections);
}

Ray Ray::transform(dito::util::Matrix m) const
{
    auto transformed_direction = m * this->direction();
    auto transformed_direction_vector = transformed_direction.to_vector();
    auto transformed_origin = m * this->origin();
    auto transformd_origin_point = transformed_origin.to_point();
    return Ray(transformd_origin_point, transformed_direction_vector);
}

Computations Ray::prepare_computations(Intersection intersection)
{

    auto t = intersection.t();
    auto object = intersection.object();
    auto point = position(t);
    auto eye_vector = direction().negate().to_vector();
    auto normal_vector = object->normal_at(point);
    bool inside = false;

    if (normal_vector.dot(eye_vector) < 0) {
        inside = true;
        normal_vector = normal_vector.negate().to_vector();
    }

    return Computations(
        object,
        point,
        eye_vector,
        normal_vector,
        t,
        inside
    );
}
