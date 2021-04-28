#include <iostream>
#include "src/util/tuple.hpp"
#include <vector>

int main(int, char**) {
    std::cout << "Hello, world!\n";
    std::vector<double> test = dito::util::point(0, 10, 32);
    std::cout << test.size() << std::endl;
}
