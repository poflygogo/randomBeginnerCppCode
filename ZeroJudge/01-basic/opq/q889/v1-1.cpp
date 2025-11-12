#include <iostream>

int main() {
    long long a, b, c, d;
    while (std::cin >> a >> b >> c >> d) {
        std::cout << c - b + a - d << '\n';
    }
}
