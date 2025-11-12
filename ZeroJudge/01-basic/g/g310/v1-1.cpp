#include <iostream>
#include <vector>

int main() {
    // --------------------------------
    // 不是很重要的 IO 優化......
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // --------------------------------

    int n;
    std::cin >> n;
    std::vector<int> arr1(n), arr2(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr1[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> arr2[i];
    }
    int cnt = 0;
    int i = n - 1;
    int j = n - 1;
    while (i >= 0 && j >= 0) {
        if (arr1[i] < arr2[j]) {
            cnt++;
            j--;
        }
        i--;
    }
    std::cout << cnt;
}
