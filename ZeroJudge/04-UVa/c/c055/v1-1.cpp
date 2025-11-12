#include <array>
#include <iomanip>
#include <iostream>

int main() {
    constexpr long long kLimit = 10000;
    constexpr long long precious = 100000;
    std::array<long long, kLimit + 1> dp = {};
    dp[1] = 1;
    for (long long i = 2; i <= kLimit; i++) {
        long long tmp = i * dp[i - 1];
        while (tmp % 10 == 0) {
            tmp /= 10;
        }
        dp[i] = tmp % precious;
    }

    int n;
    while (std::cin >> n) {
        std::cout << std::setw(5) << std::right << n << " -> " << dp[n] % 10 << '\n';
    }
}
