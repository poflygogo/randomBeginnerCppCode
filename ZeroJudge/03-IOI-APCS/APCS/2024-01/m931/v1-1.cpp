// APCS 2024-01 1. 遊戲選角
#include <algorithm>  // sort
#include <iostream>
#include <utility>  // pair
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> arr(n);  // {attack, defense}
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i].first >> arr[i].second;
    }

    // 根據平方和降序排序(題目保證所有資料的平方和互不相同)
    std::sort(arr.begin(), arr.end(), [](std::pair<int, int>& a, std::pair<int, int>& b) {
        return a.first * a.first + a.second * a.second > b.first * b.first + b.second * b.second;
    });

    // 第二大的
    std::cout << arr[1].first << ' ' << arr[1].second << '\n';
}
