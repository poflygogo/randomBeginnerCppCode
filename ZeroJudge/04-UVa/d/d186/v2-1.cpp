// Zerojudge d186
// UVa 11461 - Square Numbers
// c++14

#include <cmath>
#include <iostream>

int main() {
    int a, b;
    while (std::cin >> a >> b && a || b) {
        std::cout << std::floor(std::sqrt(b)) - std::ceil(std::sqrt(a)) + 1 << '\n';
    }
}
