#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, k, t;
    bool flag = false;
    std::cin >> n >> k >> t;
    std::vector<int> arr(k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            std::cin >> arr[j];
        }
        std::sort(arr.begin(), arr.end());
        int sum = 0;
        for (int j = 1; j < k - 1; j++) {
            sum += arr[j];
        }
        if (sum / (k - 2) >= t) {
            std::cout << i << '\n';
            flag = true;
        }
    }
    if (!flag) {
        std::cout << "A is for apple.";
    }
}
