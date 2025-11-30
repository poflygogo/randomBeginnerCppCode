// Zerojudge e287
// APCS 2019-06 2 機器人路徑
// c++14

#include <array>
#include <iostream>
#include <limits>   // numeric_limits
#include <utility>  // pair
#include <vector>

using NodeIndex = std::pair<int, int>;

int main() {
    int max_row, max_col;
    std::cin >> max_row >> max_col;
    std::vector<std::vector<int>> graph(max_row, std::vector<int>(max_col));

    int min_val = std::numeric_limits<int>::max();
    NodeIndex min_index;
    for (int r = 0; r < max_row; ++r) {
        for (int c = 0; c < max_col; ++c) {
            std::cin >> graph[r][c];
            if (graph[r][c] < min_val) {
                min_val = graph[r][c];
                min_index = {r, c};
            }
        }
    }

    constexpr std::array<NodeIndex, 4> kDirections = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};

    long long sum = 0;
    NodeIndex curr = min_index;

    do {
        sum += graph[curr.first][curr.second];
        graph[curr.first][curr.second] = -1;  // marked as used

        min_val = std::numeric_limits<int>::max();
        NodeIndex next_node;
        for (auto &d : kDirections) {
            int nr = curr.first + d.first;
            int nc = curr.second + d.second;

            if (nr < 0 || nr >= max_row) continue;
            if (nc < 0 || nc >= max_col) continue;
            if (graph[nr][nc] == -1) continue;

            if (graph[nr][nc] < min_val) {
                min_val = graph[nr][nc];
                next_node = {nr, nc};
            }
        }

        if (min_val != std::numeric_limits<int>::max()) {
            curr = next_node;
        }

    } while (graph[curr.first][curr.second] != -1);

    std::cout << sum << '\n';
}
