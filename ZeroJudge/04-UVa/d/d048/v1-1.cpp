#include <algorithm>  // std::upper_bound
#include <iomanip>    // std::setw, std::setfill
#include <iostream>
#include <string>   // std::to_string
#include <utility>  // std::pair
#include <vector>

using Time = std::pair<int, int>;

bool is_palindromic(std::string&& s) {
    size_t lft = 0;
    size_t rgt = s.size() - 1;
    while (lft < rgt) {
        if (s[lft] != s[rgt]) {
            return false;
        }
        ++lft;
        --rgt;
    }
    return true;
}

int main() {
    std::vector<Time> palindromic_times;
    Time time = {0, 0};
    while (time.first < 24) {
        if (is_palindromic(std::to_string(time.first * 100 + time.second))) {
            palindromic_times.push_back(time);
        }
        ++time.second;
        time.first += time.second / 60;
        time.second %= 60;
    }

    int t;
    std::cin >> t;
    while (t--) {
        char c;
        std::cin >> time.first >> c >> time.second;
        auto it = std::upper_bound(palindromic_times.begin(), palindromic_times.end(), time);
        if (it == palindromic_times.end()) {
            it = palindromic_times.begin();
        }
        std::cout << std::setw(2) << std::setfill('0') << it->first << ':' << std::setw(2) << std::setfill('0')
                  << it->second << '\n';
    }
}
