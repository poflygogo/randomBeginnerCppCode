#include <iostream>

int main() {
    int a, b;
    while (std::cin >> a >> b && a != -1 && b != -1) {
        int diff = std::abs(a - b);
        std::cout << (diff > 50 ? 100 - diff : diff) << '\n';
    }
}
