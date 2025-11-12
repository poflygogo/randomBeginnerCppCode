#include <algorithm>
#include <array>
#include <iostream>
#include <ostream>
#include <vector>

std::istream& operator>>(std::istream& is, std::array<int, 9>& arr) {
    for (int i = 0; i < 9; i++) {
        is >> arr[i];
    }
    return is;
}

int main() {
    std::array<int, 9> nums;
    while (std::cin >> nums) {
        if (std::all_of(nums.begin(), nums.end(), [](int n) { return n == 0; })) {
            std::cout << "0\n";
            continue;
        }

        std::reverse(nums.begin(), nums.end());
        std::string res;
        for (int i = 8; i >= 0; i--) {
            if (nums[i] == 0) {
                continue;
            }
            res.append((nums[i] > 0 ? " + " : " - "));
            res.append((std::abs(nums[i]) == 1 ? "" : std::to_string(std::abs(nums[i]))));
            res.append((i == 0 ? "" : (i == 1 ? "x" : "x^" + std::to_string(i))));
        }

        if (res.substr(0, 2) == " +") {
            res.erase(0, 3);
        } else if (res.substr(0, 2) == " -") {
            res.replace(0, 3, "-");
        }
        if (!std::isdigit(res.back()) && res.back() != 'x') {
            res += '1';
        }

        std::cout << res << '\n';
    }
}
