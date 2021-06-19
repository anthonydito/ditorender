#ifndef DITO_PHYSICS_WORLD
#define DITO_PHYSICS_WORLD

#include <vector>
#include <optional>
#include "../util/sphere.hpp"
#include "point_light.hpp"

namespace dito::physics
{
    class World
    {
    public:
        World();

        static World default_world();

        void add_object(dito::util::Sphere sphere);
        void add_point_light(dito::physics::PointLight point_light);
        std::vector<dito::util::Sphere> objects() const;
        std::vector<dito::physics::PointLight> lights() const;
        std::optional<dito::physics::PointLight> light() const;;

    private:
        std::vector<dito::util::Sphere> _objects;
        std::vector<dito::physics::PointLight> _lights;
    };
};

#endif