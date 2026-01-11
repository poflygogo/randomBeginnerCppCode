// ZeroJudge r865 社團 (Club)
// TOI 練習賽 202512 新手組 第2題
// C++14

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int main() {
    int total_stu;
    int total_club;

    std::cin >> total_stu >> total_club;

    std::vector<std::string> clubs_order(total_club);
    for (auto &&s : clubs_order) {
        std::cin >> s;
    }

    std::unordered_map<std::string, int> counter;
    while (total_stu--) {
        std::unordered_set<std::string> to_join;
        constexpr int kTotalToJoin = 3;
        for (size_t i = 0; i < kTotalToJoin; ++i) {
            std::string s;
            std::cin >> s;
            to_join.insert(s);
        }

        for (auto &&s : to_join) {
            counter[s]++;
        }
    }

    for (auto &&s : clubs_order) {
        std::cout << s << ' ' << counter.at(s) << '\n';
    }
}
