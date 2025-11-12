#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    int res = 1;
    for (int i = 0; i < dp.size(); i++) {
        if (dp[i] > res) {
            res = dp[i];
        }
    }

    std::cout << res;
}
