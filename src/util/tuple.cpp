#include "tuple.hpp"

#include <cmath>

using namespace dito;

const double COMPARE_EPSILON = 0.000001;

util::tuple util::tuple_add(const util::tuple &lhs, const util::tuple &rhs)
{
    if (lhs.size() != 4 || rhs.size() != 4)
    {
        throw std::invalid_argument("one or both of the inputs did not have a length of 4");
    }
    util::tuple output;
    for (int i = 0; i < lhs.size(); i++)
    {
        output.push_back(lhs[i] + rhs[i]);
    }
    return output;
}

util::tuple util::tuple_sub(const util::tuple &lhs, const util::tuple &rhs)
{
    if (lhs.size() != 4 || rhs.size() != 4)
    {
        throw std::invalid_argument("one or both of the inputs did not have a length of 4");
    }
    util::tuple output;
    for (int i = 0; i < lhs.size(); i++)
    {
        output.push_back(lhs[i] - rhs[i]);
    }
    return output;
}

util::tuple util::tuple_negate(const util::tuple &t)
{
    util::tuple output;
    for (const auto elem : t)
    {
        output.push_back(-elem);
    }
    return output;
}

bool util::tuple_equal(const util::tuple &lhs, const util::tuple &rhs)
{
    if (lhs.size() != rhs.size())
    {
        return false;
    }
    for (int i = 0; i < lhs.size(); ++i)
    {
        auto diff = abs(lhs[i] - rhs[i]);
        if (diff > COMPARE_EPSILON)
        {
            return false;
        }
    }
    return true;
}

util::tuple util::tuple_multiply(const util::tuple &t, double scalar)
{
    util::tuple output;
    for (const auto elem : t)
    {
        output.push_back(elem * scalar);
    }
    return output;
}

util::tuple util::tuple_divide(const util::tuple &t, double scalar)
{
    return util::tuple_multiply(t, 1 / scalar);
}

double util::tuple_magnitude(const util::tuple &t)
{
    double sum_of_squares = 0;
    for (const auto elem : t)
    {
        sum_of_squares += elem * elem;
    }
    return sqrt(sum_of_squares);
}

util::tuple util::tuple_normalize(const util::tuple &t)
{
    auto const magnitude = util::tuple_magnitude(t);
    return util::tuple_divide(t, magnitude);
}

double util::tuple_dot(const util::tuple &lhs, const util::tuple &rhs)
{
    if (lhs.size() != 4 || rhs.size() != 4)
    {
        throw std::invalid_argument("one or both of the inputs did not have a length of 4");
    }
    double output = 0;
    for (int i = 0; i < lhs.size(); ++i)
    {
        output += lhs[i] * rhs[i];
    }
    return output;
}

util::tuple util::tuple_cross(const util::tuple &lhs, const util::tuple &rhs)
{
    double x_comp = (lhs[1] * rhs[2]) - (lhs[2] * rhs[1]);
    double y_comp = (lhs[2] * rhs[0]) - (lhs[0] * rhs[2]);
    double z_comp = (lhs[0] * rhs[1]) - (lhs[1] * rhs[0]);
    return util::create_vector(x_comp, y_comp, z_comp);
}

util::tuple util::create_point(double x, double y, double z)
{
    util::tuple output = {x, y, z, 1};
    return output;
}

util::tuple util::create_vector(double x, double y, double z)
{
    util::tuple output = {x, y, z, 0};
    return output;
}
