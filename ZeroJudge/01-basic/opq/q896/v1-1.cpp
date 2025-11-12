#include <iomanip>
#include <iostream>

int main() {
    double n;
    while (std::cin >> n) {
        std::cout << std::fixed << std::setprecision(1) << n / 2 << '\n';
    }
}
