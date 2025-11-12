#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
typedef pair<short, short> Location;

bool IsValidLocation(const short &size, const vector<string> &maze, const Location &loc, const char &token) {
    return loc.first >= 0 && loc.first < size && loc.second >= 0 && loc.second < size && maze[loc.first][loc.second] != token;
}

short Solution(const short &size, const vector<string> &maze) {
    const char kBarrier = '#';
    const Location kStart = {1, 1};
    const Location kTarget = {size - 2, size - 2};
    const array<Location, 4> kDirections = {make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1)};

    vector<vector<bool>> visited(size, vector<bool>(size, false));
    visited[kStart.first][kStart.second] = true;
    queue<pair<Location, short>> q;
    q.push({kStart, 1});
    while (!q.empty()) {
        Location curr_loc = q.front().first;
        short step = q.front().second;
        q.pop();
        for (const Location &d : kDirections) {
            Location next_loc = {curr_loc.first + d.first, curr_loc.second + d.second};
            if (!IsValidLocation(size, maze, next_loc, kBarrier)) {
                continue;
            } else if (next_loc == kTarget) {
                return step + 1;
            } else if (!visited[next_loc.first][next_loc.second]) {
                q.push({next_loc, step + 1});
                visited[next_loc.first][next_loc.second] = true;
            }
        }
    }
    return -1;
}

int main() {
    short n;
    cin >> n;
    vector<string> maze(n);
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, maze[i]);
    }
    short result = Solution(n, maze);
    if (result > 0) {
        cout << result << '\n';
    } else {
        cout << "No solution!\n";
    }
}
