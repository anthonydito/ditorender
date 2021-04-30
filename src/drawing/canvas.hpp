#ifndef DITO_DRAWING_CANVAS
#define DITO_DRAWING_CANVAS

#include <vector>
#include "../util/color.hpp"

namespace dito::drawing {
    class Canvas {
        public:
            Canvas(int, int);
            int width() const;
            int height() const;
            void set_pixel(int x, int y, dito::util::Color color);
            dito::util::Color pixel(int x, int y) const;

        private:
            int _width;
            int _height;
            std::vector<std::vector<dito::util::Color>> _pixels;
    };
}

#endif
