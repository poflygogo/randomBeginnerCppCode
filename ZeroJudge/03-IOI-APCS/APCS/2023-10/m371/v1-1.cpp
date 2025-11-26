// m371
// apcs 2023-10 2. 卡牌遊戲
#include <algorithm>  // std::find_if
#include <cstddef>    // std::size_t
#include <iostream>
#include <iterator>  // std::distance
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
    int sum = 0;
    bool found;
    do {
        found = 0;

        // 橫向探索
        for (size_t r = 0; r < max_rows; ++r) {
            for (size_t c = 0; c < max_cols - 1; ++c) {
                if (graph[r][c] == -1) {
                    continue;
                }
                auto it = std::find_if(graph[r].begin() + c + 1, graph[r].end(), [](int a) { return a != -1; });
                if (it == graph[r].end()) {
                    break;
                }
                size_t c2 = std::distance(graph[r].begin(), it);
                if (graph[r][c] == graph[r][c2]) {
                    found = true;
                    sum += graph[r][c];
                    graph[r][c] = graph[r][c2] = -1;
                    c = c2;
                }
            }
        }

        // 縦向探索
        for (size_t c = 0; c < max_cols; ++c) {
            for (size_t r = 0; r < max_rows - 1; ++r) {
                if (graph[r][c] == -1) {
                    continue;
                }
                auto it = std::find_if(graph.begin() + r + 1, graph.end(),
                                       [c](const std::vector<int>& row) { return row[c] != -1; });
                if (it == graph.end()) {
                    break;
                }
                size_t r2 = std::distance(graph.begin(), it);
                if (graph[r][c] == graph[r2][c]) {
                    found = 1;
                    sum += graph[r][c];
                    graph[r][c] = graph[r2][c] = -1;
                    r = r2;
                }
            }
        }
    } while (found);
    std::cout << sum << '\n';
}

// 何等暴力...
