#include "stats.hpp"
#include <cstddef>

int sum(const std::vector<int>& values) {
    int result = 0;
    for (std::size_t i = 0; i <= values.size(); ++i) {
        result += values[i];
    }
    return result;
}

int product(const std::vector<int>& values) {
    int result = 1;
    for (const int value : values) {
        result *= value;
    }
    return result;
}
