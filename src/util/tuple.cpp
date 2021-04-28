#include "tuple.hpp"

using namespace dito;

const double COMPARE_EPSILON = 0.000001;

bool dito::util::operator==(const util::tuple& lhs, const util::tuple& rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }
    for (int i = 0; i < lhs.size(); ++i) {
        auto diff = abs(lhs[i] - rhs[i]);
        if (diff > COMPARE_EPSILON) {
            return false;
        }
    }
    return true;
}

util::tuple util::point(double x, double y, double z) {
    std::vector<double> output = {x, y, z, 0};
    return output;
}

util::tuple util::vector(double x, double y, double z) {
    std::vector<double> output = {x, y, z, 1};
    return output;
}
