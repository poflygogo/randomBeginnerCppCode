#include <array>
#include <iostream>
#include <vector>

constexpr std::array<std::pair<int, int>, 8> directions = {
    {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};

int main()
{
    int rows, cols;
    std::cin >> rows >> cols;
    std::vector<std::string> graph(rows);
    for (int i = 0; i < rows; i++)
    {
        std::cin >> graph[i];
    }

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (!std::isdigit(graph[r][c]))
            {
                continue;
            }

            std::vector<std::pair<int, int>> empty;
            for (auto &&d : directions)
            {
                int nr = r + d.first;
                int nc = c + d.second;
                if (0 <= nr && nr < rows && 0 <= nc && nc < cols && (graph[nr][nc] == '#' || graph[nr][nc] == 'P'))
                {
                    empty.push_back({nr, nc});
                }
            }

            if (empty.size() == graph[r][c] - '0')
            {
                for (auto &&[i, j] : empty)
                {
                    graph[i][j] = 'P';
                }
            }
        }
    }

    for (auto &&i : graph)
    {
        std::cout << i << '\n';
    }
}
