#ifndef DITO_PHYSICS_COMPUTATIONS
#define DITO_PHYSICS_COMPUTATIONS

#include "../util/sphere.hpp"
#include <memory>

namespace dito::physics
{
    class Computations
    {
    public:
        Computations(
            std::shared_ptr<dito::util::Sphere>,
            dito::util::Point,
            dito::util::Vector,
            dito::util::Vector,
            double,
            bool
        );

        std::shared_ptr<dito::util::Sphere> object() const;
        dito::util::Point point() const;
        dito::util::Vector eye_vector() const; 
        dito::util::Vector normal_vector() const;
        double t() const;
        bool inside() const;


    private:
        std::shared_ptr<dito::util::Sphere> _object;
        dito::util::Point _point;
        dito::util::Vector _eye_vector;
        dito::util::Vector _normal_vector;
        double _t;
        bool _inside;
    };
};

#endif