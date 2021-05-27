#ifndef DITO_UTIL_SPHERE
#define DITO_UTIL_SPHERE

#include "point.hpp"

namespace dito::util {
    class Sphere {
        public:
            Sphere();

            Point origin() const;
            bool operator==(Sphere const &other) const;
            bool operator!=(Sphere const &other) const;

        private:
            Point _origin;
    };
};

#endif