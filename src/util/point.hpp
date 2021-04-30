#ifndef DITO_UTIL_POINT
#define DITO_UTIL_POINT

#include "tuple.hpp"

namespace dito::util {
    class Point : public dito::util::Tuple
    {
        public:
            Point(double, double, double);
    };
}

#endif