// ZeroJudge r858
// TOI 練習賽 新手組 第一題 紅豆餅 (Red Bean Cake)
// C++14

#include <algorithm>  // min, max
#include <numeric>    // accumlate
#include <array>
#include <iostream>

int main() {
    // {綠豆沙, 紅豆餅1, ... , 紅豆餅5}
    std::array<int, 6> meals = {};

    int total_meal;
    std::cin >> total_meal;

    while (total_meal--) {
        int idx;
        std::cin >> idx;
        meals[idx]++;
    }

    int total_cakes = std::accumulate(meals.begin() + 1, meals.end(), 0);
    int total_combo = std::min(meals.front(), total_cakes);
    int total_cost = 0;

    total_cost += 59 * total_combo;
    total_cost += 50 * std::max(0, meals.front() - total_combo);
    total_cost += 20 * std::max(0, total_cakes - total_combo);

    for (auto val : meals) {
        std::cout << val << ' ';
    }
    std::cout << total_cost << '\n';
}
