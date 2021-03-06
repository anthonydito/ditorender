#ifndef DITO_UTIL_COLOR
#define DITO_UTIL_COLOR

#include <ostream>

namespace dito::util
{
    class Color {

    public:
        Color(double, double, double);

        static Color black();

        double red() const;
        double green() const;
        double blue() const;
        int red_255() const;
        int green_255() const;
        int blue_255() const;
        Color add(Color const &other) const;
        Color sub(Color const &other) const;
        Color mult(double scalar) const;
        Color mult(Color const &other) const;
        bool eq(Color const &other) const;

        Color operator+(Color const &other) const;
        Color operator-(Color const &other) const;
        Color operator*(double scalar) const;
        Color operator*(Color const &other) const;
        bool operator==(Color const &other) const;
        bool operator!=(Color const &other) const;
        friend std::ostream &operator<<(std::ostream &os, const Color &c);

    private:
        double _red;
        double _green;
        double _blue;
    };
}

#endif