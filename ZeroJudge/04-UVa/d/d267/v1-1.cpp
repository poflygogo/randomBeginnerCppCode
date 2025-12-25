// UVa 11577 - Letter Frequency
// ZeroJudge d267
// C++14

#include <algorithm>  // max_element
#include <array>
#include <cctype>   // isalpha, tolower
#include <cstddef>  // size_t
#include <iostream>
#include <limits>  // numeric_limits
#include <string>

int main() {
    std::array<int, 26> chars_counter;  // a-z
    int t;
    std::cin >> t;
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    while (t--) {
        std::string s;
        std::getline(std::cin, s);
        chars_counter.fill(0);

        for (char c : s) {
            if (!std::isalpha(c)) { continue; }
            c = tolower(c);
            chars_counter.at(c - 'a')++;
        }

        auto it = std::max_element(chars_counter.begin(), chars_counter.end());

        for (size_t i = 0; i < chars_counter.size(); ++i) {
            if (chars_counter[i] == *(it)) { std::cout << char('a' + i); }
        }
        std::cout << '\n';
    }
}
