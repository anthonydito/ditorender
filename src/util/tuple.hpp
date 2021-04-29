#ifndef DITO_UTIL_TUPLE
#define DITO_UTIL_TUPLE

#include <vector>

namespace dito::util
{
    using tuple = std::vector<double>;
    tuple tuple_add(const tuple &lfs, const tuple &rhs);
    tuple tuple_sub(const tuple &lfs, const tuple &rhs);
    tuple tuple_negate(const tuple &t);
    bool tuple_equal(const tuple &lfs, const tuple &rhs);
    double tuple_magnitude(const tuple &t);
    tuple tuple_normalize(const tuple &t);
    tuple tuple_multiply(const tuple &t, const double scalar);
    tuple tuple_divide(const tuple &t, const double scalar);
    tuple create_point(double x, double y, double z);
    tuple create_vector(double x, double y, double z);
};

#endif
