#include <array>
#include <climits>
#include <iostream>
#include <sstream>

using namespace std;

template <size_t N, size_t M>
istream& operator>>(istream& is, array<array<int, M>, N>& graph) {
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++) {
            is >> graph[i][j];
        }
    }
    return is;
}

int main() {
    constexpr int kMaxRow = 11;
    constexpr int kMaxCol = 11;
    constexpr int kDirections = 8;
    constexpr array<int, 8> kDeltaRow = {0, 1, 1, 1, 0, -1, -1, -1};
    constexpr array<int, 8> kDeltaCol = {1, 1, 0, -1, -1, -1, 0, 1};

    array<array<int, kMaxCol>, kMaxRow> graph;
    array<string, kMaxRow> water;
    while (cin >> graph) {
        water.fill(string(kMaxCol, '.'));

        // bfs(?)
        int r, c;
        cin >> c >> r;
        while (r != -1 && c != -1) {
            if (water[r][c] == '*') {
                cin >> c >> r;
                continue;
            }
            water[r][c] = '*';

            int nr = r, nc = c;
            int val = INT_MAX;
            for (size_t i = 0; i < kDirections; i++) {
                int tr = r + kDeltaRow[i];
                int tc = c + kDeltaCol[i];
                if (0 <= tr && tr < kMaxRow && 0 <= tc && tc < kMaxCol && graph[tr][tc] < val) {
                    nr = tr;
                    nc = tc;
                    val = graph[tr][tc];
                }
            }

            if (graph[nr][nc] < graph[r][c]) {
                r = nr;
                c = nc;
            } else {
                cin >> c >> r;
            }
        }

        for (auto&& line : water) {
            cout << line << '\n';
        }
    }
}
