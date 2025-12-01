// Zerojudge d183
// UVa 725 - Division
// c++14

#include <algorithm>  // set_intersection
#include <array>
#include <iomanip>  // setw, setfill
#include <iostream>
#include <iterator>  // back_inserter
#include <set>
#include <utility>  // pair
#include <vector>

// 紀錄不重複元素數量
// 用 set 是必要的，不能用 unordered_set，因為 set_intersection 不支援無序容器(否則得自己實現)
std::set<int> toSet(int n) {
    std::set<int> rtn;
    while (n > 0) {
        rtn.insert(n % 10);
        n /= 10;
    }
    return rtn;
}

int main() {
    constexpr int kLimit = 80;  // 79(是題目的限制)，+1 是為了做開區間
    std::array<std::vector<std::pair<int, int>>, kLimit> cache = {};

    // 01234 是 num2 理論上的最小值
    // 49876 是 num2 理論上的最大值
    for (int num2 = 01234; num2 < 49876; ++num2) {
        auto num2_set = toSet(num2);
        if (num2 < 10000) {
            num2_set.insert(0);
        }
        if (num2_set.size() != 5) continue;

        // 100000 是絕對不可能出現的數值，超過這個數值就肯定出現重複的數字
        int max_val = std::min(100000, num2 * kLimit);
        for (int num1 = num2 * 2; num1 < max_val; num1 += num2) {
            auto num1_set = toSet(num1);
            if (num1_set.size() != 5) continue;

            std::vector<int> tmp;
            std::set_intersection(num1_set.begin(), num1_set.end(), num2_set.begin(),
                                  num2_set.end(), std::back_inserter(tmp));
            if (!tmp.empty()) continue;

            cache[num1 / num2].push_back({num1, num2});
        }
    }

    for (auto &&item : cache) {
        std::sort(item.begin(), item.end());
    }

    int n;
    bool is_first_case = true;
    while (std::cin >> n && n) {
        if (!is_first_case) {
            std::cout << '\n';
        }
        is_first_case = false;
        if (cache.at(n).empty()) {
            std::cout << "There are no solutions for " << n << ".\n";
        } else {
            for (auto &&item : cache.at(n)) {
                std::cout << item.first << " / " << std::setw(5) << std::setfill('0') << item.second
                          << " = " << n << '\n';
            }
        }
    }
}
