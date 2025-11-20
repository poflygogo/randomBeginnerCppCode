#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int a, b;
        std::cin >> a >> b;
        a -= 2;
        b -= 2;
        std::cout << ((a / 3) + (a % 3 > 0)) * ((b / 3) + (b % 3 > 0)) << '\n';
    }
}
