// UVa 11417 - GCD
// ZeroJudge d255
// C++14

#include <iostream>

int gcd(int a, int b) {
    while (b) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

int main() {
    int n;
    while (std::cin >> n && n) {
        int sum = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) { sum += gcd(i, j); }
        }

        std::cout << sum << '\n';
    }
}
