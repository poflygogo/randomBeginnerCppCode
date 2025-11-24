#include <iostream>

int main() {
    long long n;
    while (std::cin >> n) {
        long long total_lines = n / 2 + 1;
        long long total_nums  = total_lines * (n + 1) / 2;
        long long last_num    = 2 * total_nums - 1;
        std::cout << (last_num - 2) * 3 << '\n';  // sum of last three nums
    }
}

// 算式還可以再精簡，但就這樣吧
// 也比較好理解「公式」怎麼來的
