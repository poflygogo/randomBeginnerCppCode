#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> arr(n, std::vector<int>(n + 1, 0));
    std::vector<int> rows_sum(n, 0), cols_sum(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> arr[i][j];
            arr[i].back() += arr[i][j];
            cols_sum[j] += arr[i][j];
        }
    }

    int row_better_cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].back() > cols_sum[i]) {
            row_better_cnt++;
        }
    }

    if (row_better_cnt > n / 2) {
        using v = const std::vector<int>;
        std::sort(arr.begin(), arr.end(), [](v& a, v& b) { return a.back() < b.back(); });
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << arr[j][i] << ' ';
            }
            std::cout << '\n';
        }
    } else {
        std::vector<std::vector<int>> tmp(n, std::vector<int>(n + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tmp[i][j] = arr[j][i];
            }
            tmp[i].back() = cols_sum[i];
        }

        using v = const std::vector<int>;
        std::sort(tmp.begin(), tmp.end(), [](v& a, v& b) { return a.back() < b.back(); });
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << tmp[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }
}
