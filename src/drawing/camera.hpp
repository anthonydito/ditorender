#ifndef DITO_DRAWING_CAMERA
#define DITO_DRAWING_CAMERA

#include "../util/matrix.hpp"
#include "../physics/ray.hpp"

namespace dito::drawing {
    class Camera {
        public:
            Camera(int, int, double);
            Camera(int, int, double, dito::util::Matrix);

            int hsize() const;
            int vsize() const;
            double field_of_view() const;
            dito::util::Matrix transform() const;
            double pixel_size() const;
            double half_width() const;
            double half_height() const;
            dito::physics::Ray ray_for_pixel(int, int);

        private:
            int _hsize;
            int _vsize;
            double _field_of_view;
            double _pixel_size;
            double _half_height;
            double _half_width;
            dito::util::Matrix _transform;

            void _compute_and_store_pixel_size_and_half_width_height();
    };
}

#endif