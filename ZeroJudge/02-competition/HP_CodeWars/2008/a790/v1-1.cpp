#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct StepInfo {
    int r, c;
};

StepInfo FindEntrance(vector<string>& graph) {
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            if (graph[i][j] == 'S') {
                return {i, j};
            }
        }
    }
    return {-1, -1};  // should not happen
}

bool FireExtinguish(vector<string>& graph) {
    for (size_t i = 0; i < graph.size(); i++) {
        for (size_t j = 0; j < graph[i].size(); j++) {
            if (graph[i][j] == 'F') {
                return false;
            }
        }
    }
    return true;
}

void Solve(vector<string>& graph, const int max_row, const int max_col, const int pipe_length) {
    static constexpr int kDirections = 4;
    static constexpr int kDirectionRow[] = {-1, 0, 0, 1};
    static constexpr int kDirectionCol[] = {0, -1, 1, 0};

    StepInfo loc = FindEntrance(graph);
    queue<StepInfo> q;
    vector<vector<int>> visited(max_row, vector<int>(max_col, 0));
    q.push(loc);
    visited[loc.r][loc.c] = 1;

    while (!q.empty()) {
        loc = q.front();
        q.pop();
        graph[loc.r][loc.c] = '.';
        int step = visited[loc.r][loc.c];
        if (step == pipe_length) {
            continue;
        }
        step++;
        for (size_t i = 0; i < kDirections; i++) {
            int r = loc.r + kDirectionRow[i];
            int c = loc.c + kDirectionCol[i];
            if (0 <= r && r < max_row && 0 <= c && c < max_col && visited[r][c] == 0 &&
                graph[r][c] != '#') {
                visited[r][c] = step;
                q.push({r, c});
            }
        }
    }

    for (auto&& line : graph) {
        cout << line << '\n';
    }
    if (FireExtinguish(graph)) {
        cout << "\nAll Fires Extinguished!\n";
    }
}

int main() {
    int max_row, max_col, pipe_length;
    while (cin >> max_col >> max_row >> pipe_length) {
        cin.ignore(INT_MAX, '\n');
        vector<string> graph(max_row);
        for (size_t i = 0; i < max_row; i++) {
            getline(cin, graph[i]);
        }
        Solve(graph, max_row, max_col, pipe_length);
    }
}
