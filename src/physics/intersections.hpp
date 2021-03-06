#ifndef DITO_PHYSICS_INTERSECTIONS
#define DITO_PHYSICS_INTERSECTIONS

#include <initializer_list>
#include <vector>
#include <optional>
#include "intersection.hpp"

namespace dito::physics
{
    class Intersections
    {
        public:
            Intersections();
            Intersections(std::initializer_list<Intersection>);
            Intersections(std::vector<Intersection>);

            void push_back(Intersection);
            std::vector<Intersection> items() const;
            int size() const;
            std::optional<Intersection> hit() const;
            Intersection operator[](int i) const;

        private:
            std::vector<Intersection> _items;
    };
};

#endif