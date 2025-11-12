#include <array>
#include <iostream>

int main() {
    constexpr int kLimit = 80;
    std::array<long long, kLimit + 1> dp;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= kLimit; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int n;
    while (std::cin >> n && n) {
        std::cout << dp[n] << '\n';
    }
}
