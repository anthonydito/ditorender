#include "world.hpp"

#include "../util/point.hpp"
#include "../util/color.hpp"
#include "../physics/material.hpp"

using namespace dito::physics;
using namespace dito::util;

World::World() {}

World World::default_world()
{
    World world;

    PointLight pl(Point(-10, 10, -10), Color(1, 1, 1));
    world.add_point_light(pl);

    Material m;
    m.set_color(Color(0.8, 1, 0.6));
    m.set_diffuse(0.7);
    m.set_specular(0.2);

    auto s1 = std::make_shared<Sphere>();
    s1->set_material(m);
    world.add_object(s1);

    auto s2 = std::make_shared<Sphere>();
    s2->set_transform(Matrix::scaling(0.5, 0.5, 0.5));
    world.add_object(s2);

    return world;
}

void World::add_object(std::shared_ptr<dito::util::Sphere> sphere)
{
    this->_objects.push_back(sphere);
}

void World::add_point_light(dito::physics::PointLight point_light)
{
    this->_lights.push_back(point_light);
}

std::vector<PointLight> World::lights() const
{
    return this->_lights;
}

std::optional<PointLight> World::light() const
{
    if (this->lights().size() == 0) {
        return std::optional<PointLight>{};
    }
    if (this->lights().size() > 1) {
        throw new std::invalid_argument("only call light when there is one light in the scene");
    }
    return this->lights()[0];
}

std::vector<std::shared_ptr<Sphere>> World::objects() const
{
    return this->_objects;
}
