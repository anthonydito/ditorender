#ifndef DITO_UTIL_VECTOR
#define DITO_UTIL_VECTOR

#include "tuple.hpp"

namespace dito::util {
    class Vector : public dito::util::Tuple
    {
        public:
            Vector();
            Vector(double, double, double);
            double magnitude() const;
            Vector normalize() const;
            double dot(const Vector &) const;
            Vector cross(const Vector &) const;

            Vector operator*(double scalar) const;
    };
}

#endif