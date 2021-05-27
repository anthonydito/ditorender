#include "intersections.hpp"

using namespace dito::physics;

Intersections::Intersections() : Intersections({}) {}

Intersections::Intersections(std::initializer_list<Intersection> items)
{
    _items = std::vector(items);
}

std::vector<Intersection> Intersections::items() const 
{
    return _items;
}

int Intersections::size() const
{
    return _items.size();
}

void Intersections::push_back(Intersection intersection)
{
    _items.push_back(intersection);
}

Intersection Intersections::operator[](int i) const
{
    return _items[i];
}