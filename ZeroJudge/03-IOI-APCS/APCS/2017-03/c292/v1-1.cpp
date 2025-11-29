// Zerojudge c292
// APCS 2017-03 3 數字龍捲風
// c++14

#include <iostream>
#include <utility>  // std::pair
#include <vector>

int main() {
    // direction:                               left,       up,     right,  down
    constexpr std::pair<int, int> directions[] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int size, d;
    std::cin >> size >> d;
    std::vector<std::vector<int>> graph(size, std::vector<int>(size));
    for (size_t i = 0; i < size; ++i) {
        for (size_t k = 0; k < size; ++k) {
            std::cin >> graph[i][k];
        }
    }

    // 只考慮移動步數，不考慮方向
    // 移動步數的規律是一個像 {1, 1, 2, 2, 3, 3, ... , 7, 7, 8} 的序列
    // 除了最後一個數字外，每個都重複兩次
    // 每換一個數字就改變方向
    int r = size / 2;
    int c = size / 2;
    for (int step = 1; step < size; ++step) {
        for (size_t t = 0; t < 2; ++t) {
            for (int cnt = 0; cnt < step; ++cnt) {
                std::cout << graph[r][c];
                r += directions[d].first;
                c += directions[d].second;
            }
            d = (d + 1) % 4;
        }
    }
    for (int cnt = 0; cnt < size; ++cnt) {
        std::cout << graph[r][c];
        r += directions[d].first;
        c += directions[d].second;
    }

    std::cout << '\n';
}
