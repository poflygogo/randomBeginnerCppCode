// ZeroJudge r866. 塗鴉連線 (Doodle)
// TOI 練習賽 202512 新手組 第3題
// C++14

#include <iostream>
#include <utility>  // pair
#include <vector>
#include <array>

int main() {
    int max_row, max_col;
    std::cin >> max_row >> max_col;

    std::vector<std::vector<int>> graph(max_row, std::vector<int>(max_col, 0));
    for (size_t i = 0; i < max_row; ++i) {
        for (size_t j = 0; j < max_col; ++j) {
            std::cin >> graph[i][j];
        }
    }

    using Node = std::pair<int, int>;

    constexpr Node kStart = {0, 0};
    const Node kEnd = {max_row - 1, max_col - 1};

    constexpr std::array<Node, 4> kDirections = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};

    Node curr = kStart;
    while (curr != kEnd) {
        int curr_step = graph[curr.first][curr.second];

        Node next_node;
        for (auto &&d : kDirections) {
            next_node = {curr.first + d.first, curr.second + d.second};
            if (next_node.first < 0 || next_node.first >= max_row) { continue; }
            if (next_node.second < 0 || next_node.second >= max_col) { continue; }
            if (next_node == kStart) { continue; }
            if (graph[next_node.first][next_node.second] == 1) {
                graph[next_node.first][next_node.second] += curr_step;
                break;
            }
        }

        curr = next_node;
    }

    std::cout << graph[kEnd.first][kEnd.second];
}
