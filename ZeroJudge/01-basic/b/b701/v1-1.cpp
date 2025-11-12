#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(vector<vector<int>> &graph, int row, int col) {
    const array<pair<int, int>, 4> kDirection = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};
    queue<pair<int, int>> q = {};
    q.push({row, col});
    int cnt = 0;
    int west = col;
    int north = row;
    int east = col;
    int south = row;
    while (!q.empty()) {
        pair<int, int> pos = q.front();
        q.pop();
        if (graph[pos.first][pos.second] == 1) {
            graph[pos.first][pos.second] = 0;
            cnt += 1;
            west = min(west, pos.second);
            north = min(north, pos.first);
            east = max(east, pos.second);
            south = max(south, pos.first);
            for (const pair<int, int> &d : kDirection) {
                q.push({pos.first + d.first, pos.second + d.second});
            }
        }
    }
    cout << west << ' ' << north << ' ' << east << ' ' << south << ' ' << cnt << '\n';
}

int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<int>> graph(row, vector<int>(col));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> graph[i][j];
        }
    }

    array<int, 4> edge_info = {0}; // west, north, east, south
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            if (graph[r][c] == 1) {
                bfs(graph, r, c);
            }
        }
    }
}
