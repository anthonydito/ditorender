#ifndef DITO_UTIL_COLOR
#define DITO_UTIL_COLOR

namespace dito::util
{
    class Color {

    public:
        Color(double, double, double);
        double red() const;
        double green() const;
        double blue() const;
        Color add(Color const &other) const;
        Color sub(Color const &other) const;
        Color mult(Color const &other) const;
        bool eq(Color const &other) const;

        Color operator+(Color const &other) const;
        Color operator-(Color const &other) const;
        Color operator*(Color const &other) const;
        bool operator==(Color const &other) const;
        bool operator!=(Color const &other) const;

    private:
        double _red;
        double _green;
        double _blue;
    };
}

#endif