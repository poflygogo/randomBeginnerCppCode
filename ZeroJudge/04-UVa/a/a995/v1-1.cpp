#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    constexpr double sqrt3 = sqrt(3);
    constexpr double sqrt7 = sqrt(7);
    double n;
    std::cout << std::fixed << std::setprecision(10);
    while (std::cin >> n) {
        std::cout << n / 2 * sqrt3 << ' '
                  << n * 3 / (3 + 2 * sqrt3) << ' '
                  << n / 2 * sqrt3 / 2 << ' '
                  << n * (6 * sqrt7 - 7 * sqrt3) / 10 << '\n';
    }
}
