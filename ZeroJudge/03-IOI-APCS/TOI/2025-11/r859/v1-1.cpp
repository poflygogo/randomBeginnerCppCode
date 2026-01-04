// ZeroJudge r859
// TOI 練習賽 新手組 第二題 樂透 (Lotto)
// C++14

#include <algorithm>  // sort, set_intersection, find
#include <iterator>   // back_inserter
#include <iostream>
#include <vector>

int intersectionCount(const std::vector<int> &guess, const std::vector<int> &target) {
    std::vector<int> tmp;
    std::set_intersection(
        guess.begin(), guess.end(), target.begin(), target.end(), std::back_inserter(tmp));
    return tmp.size();
}

bool isContain(const std::vector<int> &guess, const int target_val) {
    auto it = std::find(guess.begin(), guess.end(), target_val);
    return it != guess.end();
}

int main() {
    constexpr int kTotalNum = 6;

    std::vector<int> guess(kTotalNum);
    std::vector<int> target(kTotalNum);
    int special;

    for (auto &&i : guess) {
        std::cin >> i;
    }
    for (auto &&i : target) {
        std::cin >> i;
    }
    std::cin >> special;

    // 使用 std::set_intersection 需要使用已排序好的陣列
    std::sort(guess.begin(), guess.end());
    std::sort(target.begin(), target.end());

    int match = intersectionCount(guess, target);
    bool match_special = isContain(guess, special);

    switch (match) {
    case 6:
        std::cout << 'A';
        break;
    case 5:
        std::cout << (match_special ? 'B' : 'C');
        break;
    case 4:
        std::cout << (match_special ? 'D' : 'E');
        break;
    case 3:
        std::cout << (match_special ? 'F' : 'H');
        break;
    default:
        std::cout << (match == 2 && match_special ? 'G' : 'X');
        break;
    }
}
