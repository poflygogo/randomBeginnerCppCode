#include <cstddef>  // for size_t
#include <iostream>
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
        found = false;

        // 橫向探索
        for (size_t r = 0; r < max_rows; ++r) {
            for (size_t c = 0; c < max_cols; ++c) {
                if (graph[r][c] == -1) continue;

                // find next non -1 value
                size_t c_rgt = -1;  // -1 means not found
                for (size_t c2 = c + 1; c2 < max_cols; ++c2) {
                    if (graph[r][c2] != -1) {
                        c_rgt = c2;
                        break;
                    }
                }
                if (c_rgt != -1 && graph[r][c] == graph[r][c_rgt]) {
                    found = true;
                    sum += graph[r][c];
                    graph[r][c] = graph[r][c_rgt] = -1;
                    c = c_rgt;
                }
            }
        }

        // 縦向探索
        for (size_t c = 0; c < max_cols; ++c) {
            for (size_t r = 0; r < max_rows; ++r) {
                if (graph[r][c] == -1) continue;

                // find next non -1 value
                size_t r_btm = -1;  // -1 means not found
                for (size_t r2 = r + 1; r2 < max_rows; ++r2) {
                    if (graph[r2][c] != -1) {
                        r_btm = r2;
                        break;
                    }
                }
                if (r_btm != -1 && graph[r][c] == graph[r_btm][c]) {
                    found = true;
                    sum += graph[r][c];
                    graph[r][c] = graph[r_btm][c] = -1;
                    r = r_btm;
                }
            }
        }
    } while (found);
    std::cout << sum << '\n';
}