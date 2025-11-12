#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    // 加這行速度差三倍......
    // std::cin.tie(nullptr)->sync_with_stdio(false);

    int m, n;
    std::cin >> m >> n;
    std::vector<int> arr(m);
    for (int i = 0; i < m; i++) {
        std::cin >> arr[i];
    }
    long long sum = 0;
    while (n--) {
        int x;
        std::cin >> x;
        auto it = std::lower_bound(arr.begin(), arr.end(), x);
        sum += std::distance(arr.begin(), it) + 1;
    }
    std::cout << sum * 2;
}
