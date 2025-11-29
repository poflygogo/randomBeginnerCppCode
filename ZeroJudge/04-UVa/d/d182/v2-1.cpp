// Zerojudge d182
// UVa 256 Quirksome Squares
#include <array>
#include <iomanip>  // for std::setw, std::setfill
#include <iostream>

int power_int(int base, int exp) {
    int res = 1;
    while (exp--) {
        res *= base;
    }
    return res;
}

int main() {
    // 根據定義 Quirksome Squares 也是完全平方數
    // 考慮數字最大為 1e9-1 ，將該數字分割成兩半後相加，應介於 0 - 9999 之間
    constexpr int kLimit = 10000;
    std::array<int, kLimit> squares;
    for (int i = 0; i < kLimit; ++i) {
        squares[i] = i * i;
    }

    int n;
    while (std::cin >> n) {
        int max_possible = power_int(10, n);
        int half = power_int(10, n / 2);
        for (size_t i = 0; i < kLimit; ++i) {
            if (squares[i] >= max_possible) {
                break;
            }
            int lft = squares[i] / half;
            int rgt = squares[i] % half;
            if (power_int(lft + rgt, 2) == squares[i]) {
                std::cout << std::setw(n) << std::setfill('0') << squares[i] << '\n';
            }
        }
    }
}
