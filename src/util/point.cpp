#include "point.hpp"

using namespace dito::util;

Point::Point() : Point(0, 0, 0) {}

Point::Point(double x, double y, double z) : Tuple(x, y, z, 1) {}

Point Point::operator+(Vector const &v) const
{
    return this->add(v).to_point();
}

Point Tuple::to_point() const
{
    if (this->w() != 1)
    {
        throw std::invalid_argument("w should be 1 for point");
    }
    return Point(this->x(), this->y(), this->z());
}

std::ostream &dito::util::operator<<(std::ostream &os, const Point &p)
{
    os << "Point: x=" << p.x() << ", y=" << p.y() << ", z=" << p.z() << ", z=" << p.z() << std::endl;
    return os;
}
