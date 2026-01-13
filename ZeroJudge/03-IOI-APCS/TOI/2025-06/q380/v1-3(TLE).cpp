// ZeroJudge q380. 島嶼 (Island)
// TOI 練習賽 202506 潛力組 第1題
// C++14

#include <cstddef>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>
#include <array>

using MapInfo = std::vector<std::vector<int>>;
using Point = std::pair<int, int>;

struct PointHash {
    size_t operator()(const std::pair<int, int> &p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};

bool isValidPoint(const int max_row, const int max_col, const Point &p) {
    return 0 <= p.first && p.first < max_row && 0 <= p.second && p.second < max_col;
}

// Multi-Source BFS
int islandsDistance(const int max_row, const int max_col, const MapInfo &graph) {
    const std::array<Point, 4> kDirections = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};

    std::queue<Point> q;
    std::unordered_set<Point, PointHash> visited;

    // mark first island
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

    q.push(start);
    visited.insert(start);
    while (!q.empty()) {
        Point curr_point = q.front();
        q.pop();
        for (const Point &d : kDirections) {
            Point next_point = {curr_point.first + d.first, curr_point.second + d.second};

            if (!isValidPoint(max_row, max_col, next_point)) { continue; }
            if (visited.find(next_point) != visited.end()) { continue; }
            if (graph[next_point.first][next_point.second] != 1) { continue; }

            visited.insert(next_point);
            q.push(next_point);
        }
    }

    for (auto &&point : visited) {
        q.push(point);
    }

    MapInfo distance(max_row, std::vector<int>(max_col, 0));
    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        for (const Point &d : kDirections) {
            Point next = {curr.first + d.first, curr.second + d.second};

            if (!isValidPoint(max_row, max_col, next)) { continue; }
            if (visited.find(next) != visited.end()) { continue; }

            if (graph[next.first][next.second] == 0) {
                visited.insert(next);
                q.push(next);
                distance[next.first][next.second] = distance[curr.first][curr.second] + 1;
            } else if (graph[next.first][next.second] == 1) {
                return distance[curr.first][curr.second];
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
