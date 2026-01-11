// ZeroJudge r864
// r864. 串燒 (BBQ)
// TOI 練習賽 202512 新手組 第1題
// C++14

#include <array>
#include <iostream>

int main() {
    int total_bbq;  // barbecue
    int total_ppl;  // people
    std::cin >> total_bbq >> total_ppl;

    constexpr int kTotalTypes = 100;
    std::array<int, kTotalTypes + 1> bbq_ids = {};

    for (size_t i = 0; i < total_bbq; ++i) {
        int id;
        std::cin >> id;
        bbq_ids[id]++;
    }

    while (total_ppl--) {
        int p, id;
        std::cin >> p;
        while (p--) {
            std::cin >> id;
            bbq_ids[id]--;
        }
    }

    int excess = 0;
    int deficit = 0;
    for (const int val : bbq_ids) {
        if (val > 0) {
            excess += val;
        } else if (val < 0) {
            deficit -= val;  // deficit += abs(val)
        }
    }

    std::cout << deficit << ' ' << excess;
}
