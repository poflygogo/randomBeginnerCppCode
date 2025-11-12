#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        std::sort(arr.begin(), arr.end());
        int home;
        if (n % 2 == 0) {
            home = (arr[n / 2 - 1] + arr[n / 2]) / 2;
        } else {
            home = arr[n / 2];
        }
        int sum = std::accumulate(arr.begin(), arr.end(), 0,
                                  [home](int& a, int& b) { return a + std::abs(b - home); });
        std::cout << sum << '\n';
    }
}
