// ZeroJudge q380. 島嶼 (Island)
// TOI 練習賽 202506 潛力組 第1題
// C++14

#include <cstddef>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <array>

using MapInfo = std::vector<std::vector<int>>;
using Point = std::pair<int, int>;

bool isValidPoint(const int max_row, const int max_col, const Point &p) {
    return 0 <= p.first && p.first < max_row && 0 <= p.second && p.second < max_col;
}

// Multi-Source BFS
int islandsDistance(const int max_row, const int max_col, const MapInfo &graph) {
    const std::array<Point, 4> kDirections = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};

    std::queue<Point> q;
    std::vector<std::vector<int>> visited(max_row, std::vector<int>(max_col, -1));
    // `-1` means never visited

    // 尋找第一個島
    Point start = {-1, -1};
    for (size_t r = 0; r < max_row; ++r) {
        for (size_t c = 0; c < max_col; ++c) {
            if (graph[r][c] == 1) {
                start = {r, c};
                break;
            }
        }

        if (start.first != -1) { break; }
    }

    // 紀錄第一個島的所有座標
    q.push(start);
    visited[start.first][start.second] = 0;
    std::vector<Point> island = {start};
    while (!q.empty()) {
        Point curr = q.front();
        q.pop();
        for (auto &&d : kDirections) {
            Point next = {curr.first + d.first, curr.second + d.second};

            if (!isValidPoint(max_row, max_col, next)) { continue; }
            if (visited[next.first][next.second] == 0) { continue; }
            if (graph[next.first][next.second] != 1) { continue; }

            island.push_back(next);
            q.push(next);
            visited[next.first][next.second] = 0;
        }
    }

    for (auto &&point : island) {
        q.push(point);
    }

    // Multi-Source BFS
    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        for (auto &&d : kDirections) {
            Point next = {curr.first + d.first, curr.second + d.second};

            if (!isValidPoint(max_row, max_col, next)) { continue; }
            if (visited[next.first][next.second] != -1) { continue; }

            if (graph[next.first][next.second] == 1) {
                // 找到答案就直接退出循環
                return visited[curr.first][curr.second];
            } else if (graph[next.first][next.second] == 0) {
                q.push(next);
                visited[next.first][next.second] = visited[curr.first][curr.second] + 1;
            }
        }
    }

    return -1;  // can't find the path
}

int main() {
    int max_row, max_col;
    std::cin >> max_row >> max_col;

    MapInfo graph(max_row, std::vector<int>(max_col));
    for (auto &&row : graph) {
        for (auto &&col : row) {
            std::cin >> col;
        }
    }

    std::cout << islandsDistance(max_row, max_col, graph);
}
