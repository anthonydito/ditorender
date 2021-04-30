#ifndef DITO_UTIL_COLOR
#define DITO_UTIL_COLOR

namespace dito::util
{
    class Color {

    public:
        Color(double, double, double);
        double red();
        double green();
        double blue();

    private:
        double _red;
        double _green;
        double _blue;
    };
}

#endif