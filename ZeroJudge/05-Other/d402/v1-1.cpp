// ZeroJudge d402 1.擾亂專家
// C++14

#include <algorithm>  // find_if, find_if_not
#include <cstddef>    // isdigit
#include <iterator>   // distance
#include <array>
#include <iostream>
#include <string>

int main() {
    // 總共兩個數字，如果還有類似的題目，只需要改這個參數就可以直接複用
    constexpr int kNumbersToFind = 2;

    std::string line;
    std::array<int, kNumbersToFind> nums = {};
    size_t idx = 0;

    while (idx < nums.size() && std::getline(std::cin, line)) {
        auto it = std::find_if(line.begin(), line.end(), [&](const char c) { return isdigit(c); });

        while (idx < nums.size() && it != line.end()) {
            auto it2 = std::find_if_not(it, line.end(), [&](const char c) { return isdigit(c); });

            size_t start = std::distance(line.begin(), it);
            size_t end = std::distance(line.begin(), it2);
            nums[idx] = std::stoi(line.substr(start, end - start));
            idx++;

            it = std::find_if(it2, line.end(), [&](const char c) { return isdigit(c); });
        }
    }

    // 題目僅保證 a 和 b 在 int 的範圍內，但不保證他們的和也在 int 的範圍內
    long long sum = 0;
    for (const int num : nums) {
        std::cout << num << ' ';
        sum += num;
    }
    std::cout << sum;
}
