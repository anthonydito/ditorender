#ifndef DITO_PHYSICS_POINT_LIGHT
#define DITO_PHYSICS_POINT_LIGHT

#include "../util/color.hpp"
#include "../util/point.hpp"

namespace dito::physics
{
    class PointLight
    {

        public:
            PointLight(dito::util::Point position, dito::util::Color intensity);

            dito::util::Point position() const;
            dito::util::Color intensity() const;

        private:
            dito::util::Point _position;
            dito::util::Color _intensity;
    };
};

#endif