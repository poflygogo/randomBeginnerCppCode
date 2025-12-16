// 11352 - Crazy King
// ZeroJudge d191
// C++14

#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Point {
    int row, col;

    Point() : row(0), col(0) {};
    Point(int row, int col) : row(row), col(col) {};

    // 重載 `==` 運算子，方便比較
    friend bool operator==(const Point &a, const Point &b) {
        return a.row == b.row && a.col == b.col;
    }

    // 重載 `+` 運算子，簡化寫法
    friend Point operator+(const Point &a, const Point &b) {
        return Point(a.row + b.row, a.col + b.col);
    }
};

int solve(const int max_row, const int max_col, std::vector<std::string> &graph) {
    // 查找關鍵資訊
    Point start, target;
    std::vector<Point> knight;
    for (int r = 0; r < max_row; ++r) {
        for (int c = 0; c < max_col; ++c) {
            switch (graph[r][c]) {
            case 'A':
                start = {r, c};
                break;
            case 'B':
                target = {r, c};
                break;
            case 'Z':
                knight.push_back({r, c});
            }
        }
    }

    static const std::array<Point, 8> knight_step = {
        {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}}};
    static const std::array<Point, 8> king_step = {
        {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};

    // 懶惰開新的函式了，這樣要寫的參數少一點點
    static auto isValid = [&](Point &p) {
        return 0 <= p.row && p.row < max_row && 0 <= p.col && p.col < max_col;
    };

    // 騎士攻擊
    for (const Point &k : knight) {
        for (const Point &kd : knight_step) {
            Point nk = k + kd;
            if (isValid(nk) && graph[nk.row][nk.col] == '.') { graph[nk.row][nk.col] = 'Z'; }
        }
    }

    // bfs
    std::queue<Point> q;
    std::vector<std::vector<int>> visited(max_row, std::vector<int>(max_col, -1));
    q.push(start);
    visited[start.row][start.col] = 0;
    while (!q.empty()) {
        Point curr = q.front();
        q.pop();
        for (const Point &d : king_step) {
            Point np = curr + d;
            if (!isValid(np)) { continue; }
            if (visited[np.row][np.col] != -1) { continue; }
            if (np == target) { return visited[curr.row][curr.col] + 1; }
            if (graph[np.row][np.col] != 'Z') {
                visited[np.row][np.col] = visited[curr.row][curr.col] + 1;
                q.push({np});
            }
        }
    }

    return 0;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int m, n;
        std::cin >> m >> n;
        std::vector<std::string> graph(m);
        for (auto &&line : graph) { std::cin >> line; }
        int result = solve(m, n, graph);
        if (result) {
            std::cout << "Minimal possible length of a trip is " << result << '\n';
        } else {
            std::cout << "King Peter, you can't go now!\n";
        }
    }
}
