#include <algorithm>
#include <iostream>

int main() {
    std::string s;
    while (std::getline(std::cin, s)) {
        int sum = 0;
        auto it = std::find_if(s.begin(), s.end(), [](char c) { return std::isalpha(c); });
        while (it < s.end()) {
            auto j = std::find_if(it, s.end(), [](char c) { return !std::isalpha(c); });
            if (j > it) {
                sum++;
            }
            it = std::find_if(j, s.end(), [](char c) { return std::isalpha(c); });
        }
        std::cout << sum << '\n';
    }
}
