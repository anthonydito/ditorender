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

std::optional<Intersection> Intersections::hit() const
{
    std::optional<Intersection> curr_smallest = {};
    for (Intersection i : items())
    {
        if (i.t() < 0)
        {
            continue;
        }
        if (curr_smallest.has_value())
        {
            if (curr_smallest.value().t() > i.t())
            {
                curr_smallest.emplace(i);
            }
        }
        else
        {
            curr_smallest.emplace(i);
        }
    }
    return curr_smallest;
}

Intersection Intersections::operator[](int i) const
{
    return _items[i];
}
