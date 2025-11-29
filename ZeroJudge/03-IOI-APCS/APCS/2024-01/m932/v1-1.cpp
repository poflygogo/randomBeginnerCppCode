// APCS 2024-01 2. 蜜蜂觀察
#include <iostream>
#include <string>
#include <utility>  // std::pair
#include <vector>

int main() {
    int max_rows, max_cols, steps;
    std::cin >> max_rows >> max_cols >> steps;
    std::vector<std::string> graph(max_rows);  // hexagon graph
    for (int i = 0; i < max_rows; i++) {
        std::cin >> graph[i];
    }

    // 6 directions:                              右上,     右,     右下,   左下,   左,       左上
    constexpr std::pair<int, int> directions[] = {{-1, 0}, {0, 1}, {1, 1}, {1, 0}, {0, -1}, {-1, -1}};

    int curr_r = max_rows - 1, curr_c = 0;  // start at bottom-left
    std::string path;
    path.reserve(steps);
    int diff_blocks = 0;
    while (steps--) {
        int d;
        std::cin >> d;
        int next_r = curr_r + directions[d].first;
        int next_c = curr_c + directions[d].second;
        if (0 <= next_r && next_r < max_rows && 0 <= next_c && next_c < max_cols) {
            curr_r = next_r;
            curr_c = next_c;
        }
        diff_blocks += (path.find(graph[curr_r][curr_c]) == std::string::npos);
        path += graph[curr_r][curr_c];
    }

    std::cout << path << '\n' << diff_blocks << '\n';
}
