#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>

constexpr int size = 13;

bool IsValid(const std::string& s) {
    int sum_odd = 0;
    int sum_even = 0;
    for (int i = 0; i < size - 1; i += 2) {
        sum_odd += s[i] - '0';
        sum_even += s[i + 1] - '0';
    }
    int check = (sum_odd + 3 * sum_even) % 10 + (s.back() - '0');
    return check == 10 || check == 0;
}

int main() {
    int n;
    std::cin >> n;
    std::string s;
    s.reserve(size);
    std::map<std::string, int> counter;
    while (n--) {
        std::cin >> s;
        if (IsValid(s)) {
            counter[s.substr(0, 3)]++;
        }
    }

    using item = std::pair<std::string, int>;
    auto res = std::max_element(counter.begin(), counter.end(), [](const item& a, const item& b) { return a.second < b.second; });
    std::cout << res->first << ' ' << res->second;
}
