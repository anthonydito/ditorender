// #ifndef DITO_UTIL_TUPLE
// #define DITO_UTIL_TUPLE

#include <vector>

namespace dito::util {
    using tuple = std::vector<double>;
    bool operator==(const tuple& lefs, const tuple& rhs);
    tuple point(double x, double y, double z);
    tuple vector(double x, double y, double z);
};

// #endif