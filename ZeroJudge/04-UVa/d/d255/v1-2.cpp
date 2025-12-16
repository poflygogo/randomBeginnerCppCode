// UVa 11417 - GCD
// ZeroJudge d255
// C++14

#include <array>
#include <iostream>
#include <utility>

int gcd(int a, int b) {
    static std::array<std::array<int, 501>, 501> cache = {};

    if (a > b) { std::swap(a, b); }
    auto it = cache.at(a).begin() + b;
    if (*it != 0) { return *it; }

    while (b) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }

    *it = a;
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
