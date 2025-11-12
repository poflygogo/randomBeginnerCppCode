#include <iostream>

int main() {
    long long a, b;
    while (std::cin >> a >> b) {
        std::cout << std::abs(a - b) << '\n';
    }
}
