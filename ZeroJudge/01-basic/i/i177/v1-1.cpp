#include <array>
#include <iostream>
#include <queue>
#include <vector>

constexpr std::array<std::pair<int, int>, 4> directions = {{{-1, 0}, {0, -1}, {0, 1}, {1, 0}}};

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int rows, cols, x, y, z;
    std::cin >> rows >> cols >> x >> y >> z;
    std::vector<std::vector<int>> graph(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> graph[i][j];
        }
    }

    x--;
    y--;

    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    int origin = graph[x][y];
    std::queue<std::pair<int, int>> q;
    if (origin != z)
    {
        q.push({x, y});
        visited[x][y] = true;
    }

    while (!q.empty())
    {
        std::pair<int, int> *c = &q.front();
        graph[c->first][c->second] = z;
        for (const std::pair<int, int> &d : directions)
        {
            int nr = c->first + d.first;
            int nc = c->second + d.second;
            if (0 <= nr && nr < rows && 0 <= nc && nc < cols && !visited[nr][nc] && graph[nr][nc] == origin)
            {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
        q.pop();
    }

    for (auto &&line : graph)
    {
        for (auto &&i : line)
        {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
}
