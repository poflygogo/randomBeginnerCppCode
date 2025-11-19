#include <array>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Location {
    int d, r, c;
};

int Solve(const vector<vector<string>>& graph, const int max_depth, const int max_row,
          const int max_col, Location& start) {
    static const array<Location, 6> kDirections = {
        {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}}};
    vector<vector<vector<int>>> visited(max_depth,
                                        vector<vector<int>>(max_row, vector<int>(max_col, 0)));
    queue<Location> q;
    q.push(start);
    while (!q.empty()) {
        Location curr = q.front();
        q.pop();
        for (auto&& d : kDirections) {
            Location next = {curr.d + d.d, curr.r + d.r, curr.c + d.c};
            if (0 <= next.d && next.d < max_depth && 0 <= next.r && next.r < max_row &&
                0 <= next.c && next.c < max_col && visited[next.d][next.r][next.c] == 0 &&
                graph[next.d][next.r][next.c] != '#') {
                visited[next.d][next.r][next.c] = visited[curr.d][curr.r][curr.c] + 1;
                if (graph[next.d][next.r][next.c] == 'E') {
                    return visited[next.d][next.r][next.c];
                }
                q.push(next);
            }
        }
    }
    return -1;
}

int main() {
    int depth, max_row, max_col;
    while (cin >> depth >> max_row >> max_col && depth && max_row && max_col) {
        vector<vector<string>> graph(depth, vector<string>(max_row));
        Location start;
        bool found_start = false;
        for (int d = 0; d < depth; d++) {
            for (int r = 0; r < max_row; r++) {
                cin >> graph[d][r];
                if (!found_start) {
                    int c = graph[d][r].find('S');
                    if (c != graph[d][r].npos) {
                        start = {d, r, c};
                        found_start = true;
                    }
                }
            }
        }
        int res = Solve(graph, depth, max_row, max_col, start);
        if (res == -1) {
            cout << "Trapped!\n";
        } else {
            cout << "Escaped in " << res << " minute(s).\n";
        }
    }
}
