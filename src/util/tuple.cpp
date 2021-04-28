#include "tuple.hpp"

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
