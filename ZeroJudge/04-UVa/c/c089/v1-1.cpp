#include <algorithm>  // reserve
#include <iomanip>    // setw
#include <iostream>

int main() {
    const std::string kTokens = "0123456789ABCDEF";
    constexpr int kWidth = 7;
    std::string num_str;
    int base, base_target;
    while (std::cin >> num_str >> base >> base_target) {
        int num_int = std::stoi(num_str, nullptr, base);

        std::string res;
        while (num_int) {
            res += kTokens[num_int % base_target];
            num_int /= base_target;
        }
        if (res.empty()) {
            res = "0";
        } else {
            std::reverse(res.begin(), res.end());
        }
        std::cout << std::setw(kWidth) << (res.size() > kWidth ? "ERROR" : res) << '\n';
    }
}
