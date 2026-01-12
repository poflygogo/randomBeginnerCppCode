// ZeroJudge p911. 橋牌 (Bridge)
// TOI 練習賽 2025-06 新手組 第3題
// C++14

#include <array>
#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    constexpr int kTotalCard = 13;
    constexpr int kTotalSuit = 4;
    const std::unordered_map<char, int> kSuitId = {{'S', 0}, {'H', 1}, {'D', 2}, {'C', 3}};
    const std::unordered_map<char, int> kHCP = {{'A', 4}, {'K', 3}, {'Q', 2}, {'J', 1}};

    std::array<int, kTotalSuit> suit_counter = {};
    int score = 0;

    for (size_t i = 0; i < kTotalCard; ++i) {
        std::string card;
        std::cin >> card;
        suit_counter[kSuitId.at(card.front())]++;
        if (kHCP.find(card.back()) != kHCP.end()) { score += kHCP.at(card.back()); }
    }

    for (size_t i = 0; i < kTotalSuit; ++i) {
        std::cout << suit_counter[i] << (i + 1 < kTotalSuit ? ' ' : '\n');
    }
    std::cout << score;
}
