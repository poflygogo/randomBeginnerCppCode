#include <iostream>

int main() {
    int n;
    while (std::cin >> n && n) {
        std::cout << n * (n + 1) * (2 * n + 1) / 6 << '\n';
    }
}
