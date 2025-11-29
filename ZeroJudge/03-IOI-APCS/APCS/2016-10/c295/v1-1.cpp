// ZeroJudge c295
// APCS 2016-10 2 最大和
// C++14

#include <algorithm>  // std::max_element
#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> data(n, std::vector<int>(m));

    int sum = 0;
    std::vector<int> max_nums(n);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            std::cin >> data[i][j];
        }
        max_nums[i] = *std::max_element(data[i].begin(), data[i].end());
        sum += max_nums[i];
    }

    std::cout << sum << '\n';

    std::vector<int> factors;
    for (size_t i = 0; i < n; ++i) {
        if (sum % max_nums[i] == 0) {
            factors.push_back(max_nums[i]);
        }
    }

    if (factors.empty()) {
        std::cout << -1 << '\n';
    } else {
        for (size_t i = 0; i < factors.size(); ++i) {
            std::cout << factors[i] << (i == factors.size() - 1 ? '\n' : ' ');
        }
    }
}
