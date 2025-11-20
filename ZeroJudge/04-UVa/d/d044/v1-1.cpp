#include <array>
#include <iostream>

using namespace std;

int digits_sum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    constexpr int kLimit = 1000000;
    array<bool, kLimit + 1> dp;
    dp.fill(false);
    for (int i = 1; i <= kLimit; ++i) {
        if (dp[i]) {
            continue;
        }
        int n = i + digits_sum(i);
        while (n <= kLimit && !dp[n]) {
            dp[n] = true;
            n = n + digits_sum(n);
        }
    }

    for (int i = 1; i <= kLimit; ++i) {
        if (!dp[i]) {
            cout << i << '\n';
        }
    }
}
