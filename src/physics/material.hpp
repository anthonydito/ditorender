#ifndef DITO_PHYSICS_MATERIAL
#define DITO_PHYSICS_MATERIAL

#include "../util/color.hpp"
#include "point_light.hpp"

namespace dito::physics
{
    class Material
    {
        public:
            Material();

            dito::util::Color color() const;
            double ambient() const;
            double diffuse() const;
            double specular() const;
            double shininess() const;

            void set_ambient(double);
            void set_diffuse(double);
            void set_specular(double);
            void set_shininess(double);

            dito::util::Color lighting(PointLight, dito::util::Point, dito::util::Vector, dito::util::Vector) const;

            void set_color(dito::util::Color color);

            bool operator==(const Material &) const;


        private:
            dito::util::Color _color;
            double _ambient;
            double _diffuse;
            double _specular;
            double _shininess;
    };
};

#endif