#ifndef DITO_SIM_ENVIRONMENT
#define DITO_SIM_ENVIRONMENT

#include "../util/vector.hpp"
#include "../util/point.hpp"

using namespace dito::util;

namespace dito::sim
{
    class Environment {
    public:
        Environment(Vector, Vector);

        Vector gravity();
        Vector wind();

    private:
        Vector _gravity;
        Vector _wind;
    };
}

#endif
