#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int val = 1;
    for (int i = 0; i <= n; i++) {
        std::cout << "2^" << i << " = " << val << '\n';
        val <<= 1;
    }
}
