#include "stats.hpp"
#include <iostream>
#include <vector>

int main() {
    const std::vector<int> values = {12, 15, 20, 25, 30, 35, 40};
    std::cout << "Сумма: " << sum(values) << '\n';
    std::cout << "Произведение: " << product(values) << '\n';
    return 0;
}
