// UVa 11388 - GCD LCM
// ZeroJudge d256
// C++14

#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int a, b;
        std::cin >> a >> b;

        if (b % a == 0) {
            std::cout << a << ' ' << b << '\n';
        } else {
            std::cout << -1 << '\n';
        }
    }
}
