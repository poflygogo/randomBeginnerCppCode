#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    double a, b;
    while (std::cin >> a >> b) {
        std::cout << std::fixed << std::setprecision(0) << floor(round(pow(b, 1 / a))) << '\n';
    }
}
