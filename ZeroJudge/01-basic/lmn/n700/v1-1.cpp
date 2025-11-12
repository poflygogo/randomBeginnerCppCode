#include <array>
#include <iostream>
#include <queue>
#include <vector>

constexpr std::array<std::pair<int, int>, 8> directions = {
    {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};

int main() {
    int rows, cols, r, c;
    std::cin >> rows >> cols >> r >> c;
    std::vector<std::string> graph(rows);
    for (int i = 0; i < rows; i++) {
        std::cin >> graph[i];
    }

    std::vector<std::string> result(rows, std::string(cols, '#'));
    std::queue<std::pair<int, int>> q;
    q.push({r - 1, c - 1});
    while (!q.empty()) {
        std::pair<int, int> curr = q.front();
        q.pop();
        int cnt = 0;
        std::vector<std::pair<int, int>> tmp;

        for (auto&& d : directions) {
            int nr = curr.first + d.first;
            int nc = curr.second + d.second;
            if (0 <= nr && nr < rows && 0 <= nc && nc < cols && result[nr][nc] == '#') {
                if (graph[nr][nc] == '*') {
                    cnt++;
                } else {
                    tmp.push_back({nr, nc});
                }
            }
        }

        if (cnt > 0) {
            result[curr.first][curr.second] = cnt + '0';
        } else {
            result[curr.first][curr.second] = '_';
            for (int i = 0; i < tmp.size(); i++) {
                q.push(tmp[i]);
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        std::cout << result[i] << '\n';
    }
}
