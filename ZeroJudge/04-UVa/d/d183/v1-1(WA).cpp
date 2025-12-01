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

std::set<int> toSet(int n) {
    std::set<int> rtn;
    while (n > 0) {
        rtn.insert(n % 10);
        n /= 10;
    }
    return rtn;
}

int main() {
    constexpr int kLimit = 80;
    std::array<std::vector<std::pair<int, int>>, kLimit> cache = {};

    for (int num2 = 01234; num2 < 49876; ++num2) {
        auto num2_set = toSet(num2);
        num2_set.insert(0);
        if (num2_set.size() != 5) continue;

        int max_val = std::min(100000, num2 * 80);
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
