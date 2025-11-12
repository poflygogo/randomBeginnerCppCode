#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// 用於標示座標/方向的資訊
// 其實也可以用 pair，只是我覺得這樣語意更清晰一點
struct Coordinate {
    int row;
    int col;

    // 是否是合法的座標
    bool is_valid(const int &size) const { return row >= 0 && row < size && col >= 0 && col < size; }

    // 重載 '==' 運算子
    bool operator==(const Coordinate &other) const { return row == other.row && col == other.col; }

    // 該座標是否已被記錄過
    bool is_visited(const vector<vector<bool>> &visited) const { return visited[row][col]; }

    // 該座標在對應 graph 的資訊
    char info(const vector<string> &maze) const { return maze[row][col]; }
};

/**
 * @brief 返回一個 size x size 的 maze 中，從起點到終點的最短路徑長度。(bfs)
 * @param size 迷宮的尺寸 (<= 100)
 * @param maze 迷宮的資料，n 行 n 列，由 '#' 和 '.' 構成的迷宮。
 * @return 如果沒有任何路徑可抵達，將返回 -1。
 */
int Solution(const int &size, const vector<string> &maze) {
    const char kBarrier = '#';
    const Coordinate kStart = {1, 1};                // 起點固定是 (1, 1)
    const Coordinate kTarget = {size - 2, size - 2}; // 終點固定是 (size - 2, size - 2)
    const array<Coordinate, 4> kDirections = {{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};

    vector<vector<bool>> visited(size, vector<bool>(size, false));
    visited[kStart.row][kStart.col] = true;
    queue<pair<Coordinate, int>> q;
    q.push({kStart, 1});

    while (!q.empty()) {
        Coordinate loc_curr = q.front().first;
        int step = q.front().second + 1;
        q.pop();

        for (const Coordinate &d : kDirections) {
            Coordinate loc_next = {loc_curr.row + d.row, loc_curr.col + d.col};
            if (!loc_next.is_valid(size) || loc_next.is_visited(visited) || loc_next.info(maze) == kBarrier) {
                continue;
            } else if (loc_next == kTarget) {
                return step;
            } else {
                visited[loc_next.row][loc_next.col] = true;
                q.push({loc_next, step});
            }
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<string> maze(n);
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, maze[i]);
    }
    int result = Solution(n, maze);
    if (result > 0) {
        cout << result << '\n';
    } else {
        cout << "No solution!\n";
    }
}
