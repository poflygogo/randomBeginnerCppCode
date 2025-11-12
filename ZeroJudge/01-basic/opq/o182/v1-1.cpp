#include <iostream>
#include <numeric>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int t = std::accumulate(arr.begin() + i, arr.begin() + j, 0);
            if (res < t && t <= k) {
                res = t;
            }
        }
    }
    std::cout << res;
}
