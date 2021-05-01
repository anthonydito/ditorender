#ifndef DITO_UTIL_POINT
#define DITO_UTIL_POINT

#include "tuple.hpp"
#include "vector.hpp"

namespace dito::util {
    class Point : public dito::util::Tuple
    {
        public:
            Point();
            Point(double, double, double);

            Point operator+(Vector const &v) const;
    };
}

#endif