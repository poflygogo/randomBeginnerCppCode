// ZeroJudge p910. 午餐 (Lunch)
// TOI 練習賽 2025-06 新手組 第2題
// C++14

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>  // pair

int main() {
    int max_row, max_col;
    std::cin >> max_row >> max_col;

    using Locate = std::pair<int, int>;
    std::unordered_map<std::string, std::vector<Locate>> data;
    for (int i = 1; i <= max_row; ++i) {
        for (int j = 1; j <= max_col; ++j) {
            std::string s;
            std::cin >> s;
            data[s].push_back({i, j});
        }
    }

    std::string target;
    std::cin >> target;
    auto &result = data[target];
    if (result.empty()) {
        // unordered_map 使用 [] 取不存在的元素時，會自動插入並初始化
        // 而 vector 初始化時是一個空陣列，可利用此特性檢查是否應輸出 "0 0"
        // 這邊也可以用 `data.find(target) != data.end()` 判斷
        std::cout << "0 0";
    } else {
        for (const Locate &val : result) {
            std::cout << val.first << ' ' << val.second << '\n';
        }
    }
}
