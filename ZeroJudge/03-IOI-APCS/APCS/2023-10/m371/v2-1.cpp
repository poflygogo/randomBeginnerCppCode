#include <array>
#include <cstddef>  // for size_t
#include <iostream>
#include <utility>  // for std::pair
#include <vector>

int main() {
    int max_rows, max_cols;
    std::cin >> max_rows >> max_cols;
    std::vector<std::vector<int>> graph(max_rows, std::vector<int>(max_cols));
    for (size_t r = 0; r < max_rows; ++r) {
        for (size_t c = 0; c < max_cols; ++c) {
            std::cin >> graph[r][c];
        }
    }

    const std::array<std::pair<int, int>, 2> directions = {{{1, 0}, {0, 1}}};  // 右、下
    int sum = 0;
    bool found;
    do {
        found = false;
        for (size_t r = 0; r < max_rows; ++r) {
            for (size_t c = 0; c < max_cols; ++c) {
                if (graph[r][c] == -1) {
                    continue;
                }

                for (const auto& d : directions) {
                    size_t r2 = r + d.first;
                    size_t c2 = c + d.second;

                    // 往該方向延伸，直到撞牆或遇到非 -1 的卡牌
                    while (r2 < max_rows && c2 < max_cols && graph[r2][c2] == -1) {
                        r2 += d.first;
                        c2 += d.second;
                    }

                    // 檢查是否停在合法的格子 (沒越界) 且數值相同
                    if (r2 < max_rows && c2 < max_cols && graph[r2][c2] == graph[r][c]) {
                        found = true;
                        sum += graph[r][c];
                        graph[r][c] = -1;
                        graph[r2][c2] = -1;
                        break;  // 找到配對後就停止搜尋(每個位置最多只會成功配對一次)
                    }
                }
            }
        }
    } while (found);

    std::cout << sum << '\n';
}
