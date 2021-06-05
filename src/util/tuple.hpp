#ifndef DITO_UTIL_TUPLE
#define DITO_UTIL_TUPLE

#include <ostream>

namespace dito::util
{

    class Vector;
    class Point;
    class Matrix;

    class Tuple
    {
    public:
        Tuple(const Point p);
        Tuple(const Tuple &t);
        Tuple(double, double, double, double);
        double x() const;
        double y() const;
        double z() const;
        double w() const;
        Tuple sub(const Tuple &) const;
        Tuple add(const Tuple &) const;
        bool eq(const Tuple &) const;
        Tuple negate() const;
        Tuple multiply(double) const;
        double dot(const Tuple &other) const;
        Tuple divide(double) const;
        Vector to_vector() const;
        Point to_point() const;

        Tuple operator+(Tuple const &other) const;
        Tuple operator-(Tuple const &other) const;
        bool operator==(Tuple const &other) const;
        Tuple operator*(double scalar) const;
        friend std::ostream &operator<<(std::ostream &os, const Tuple &t);

    private:
        double _x;
        double _y;
        double _z;
        double _w;
    };
};

std::ostream &operator<<(std::ostream &os, const dito::util::Tuple &obj);

#endif
