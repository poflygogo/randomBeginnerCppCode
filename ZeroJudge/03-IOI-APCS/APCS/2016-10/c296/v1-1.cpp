// ZeroJudge c297
// APCS 2016-10 4 棒球遊戲
// C++14

#include <algorithm>  // std::rotate, std::fill
#include <array>
#include <cstddef>  // size_t
#include <iostream>
#include <numeric>  // std::accumulate
#include <string>
#include <vector>

template <size_t T>
int calc_score(std::array<std::vector<std::string>, T> records, int target_out) {
    constexpr int kTotalHits = 5;    // 每位球員最多打五球(題目給的)
    std::array<bool, 3> bases = {};  // {三壘, 二壘, 一壘}
    int score = 0;
    int out = 0;
    for (int i = 0; i < kTotalHits; i++) {
        for (auto &&player : records) {
            // 當球員已經把所有球都打完了
            if (i >= player.size()) {
                break;
            }

            std::string &rec = player.at(i);
            if (rec == "HR") {  // home run
                score += std::accumulate(bases.begin(), bases.end(), 0);
                score += 1;  // the hitter
                bases.fill(false);
            } else if (rec.at(1) == 'B') {  // 1B, 2B, 3B
                int hit = rec.at(0) - '0';
                score += std::accumulate(bases.begin(), bases.begin() + hit, 0);
                // 跑者移動
                std::rotate(bases.begin(), bases.begin() + hit, bases.end());
                // 打擊者上壘
                bases[3 - hit] = true;
                // 返回本壘者歸零
                std::fill(bases.begin() + (3 - hit) + 1, bases.end(), false);
            } else {  // res == "FO" or "GO" or "SO"
                out++;
                target_out--;
            }

            // 達到目標就提前返回
            if (target_out == 0) {
                return score;
            }

            // 每三出局就清空一次壘包
            if (out == 3) {
                out = 0;
                bases.fill(false);
            }
        }
    }
    return score;
}

int main() {
    constexpr int kTotalPlayers = 9;
    std::array<std::vector<std::string>, kTotalPlayers> players_records;
    for (auto &&player : players_records) {
        int size;
        std::cin >> size;
        player.resize(size);
        for (auto &&record : player) {
            std::cin >> record;
        }
    }

    int target_out;
    std::cin >> target_out;
    std::cout << calc_score(players_records, target_out) << '\n';
}
