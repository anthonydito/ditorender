#ifndef DITO_UTIL_SPHERE
#define DITO_UTIL_SPHERE

#include "point.hpp"
#include "matrix.hpp"
#include "vector.hpp"

namespace dito::util {
    class Sphere {
        public:
            Sphere();

            Point origin() const;
            Matrix transform() const;
            Vector normal_at(Point p) const;

            void set_transform(Matrix);
            bool operator==(Sphere const &other) const;
            bool operator!=(Sphere const &other) const;

        private:
            Point _origin;
            Matrix _transform;
    };
};

#endif