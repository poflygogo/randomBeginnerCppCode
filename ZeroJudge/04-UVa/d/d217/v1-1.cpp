// UVa 489 - Hangman Judge
// ZeroJudge d217
// C++14

#include <array>
#include <bitset>
#include <iostream>
#include <string>

enum class Result { WIN, LOSE, CHICKEN };

Result hangmanJudge(const std::string &target, const std::string &guess) {
    static constexpr int kTotalChars = 26;
    static constexpr int kScoreLimit = 7;
    static std::bitset<kTotalChars> chars(0), visited(0);
    chars.reset();
    visited.reset();

    for (const char c : target) { chars[c - 'a'] = true; }

    int score = 0;
    for (const char c : guess) {
        char i = c - 'a';
        if (visited[i]) continue;

        if (chars[i]) {
            chars[i] = false;
            if (!chars.any()) { return Result::WIN; }
        } else {
            score++;
            if (score >= kScoreLimit) { return Result::LOSE; }
        }

        visited[i] = true;
    }

    return Result::CHICKEN;
}

int main() {
    const std::array<std::string, 3> kResultText = {"win", "lose", "chickened out"};
    int n;
    while (std::cin >> n && n != -1) {
        std::string target, guess;
        std::cin >> target >> guess;

        std::cout << "Round " << n << '\n'
                  << "You " << kResultText[(int)hangmanJudge(target, guess)] << ".\n";
    }
}
