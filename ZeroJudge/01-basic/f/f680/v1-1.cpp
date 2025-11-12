#include <iostream>
#include <vector>

void dfs(const int size, std::vector<std::vector<int>> &graph, int r, int c, int target)
{
    if (0 <= r && r < size && 0 <= c && c < size && graph[r][c] == target)
    {
        graph[r][c] = 0;
        dfs(size, graph, r - 1, c, target);
        dfs(size, graph, r + 1, c, target);
        dfs(size, graph, r, c - 1, target);
        dfs(size, graph, r, c + 1, target);
    }
}

int main()
{
    int size;
    std::cin >> size;
    std::vector<std::vector<int>> graph(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cin >> graph[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (graph[i][j] != 0)
            {
                cnt++;
                dfs(size, graph, i, j, graph[i][j]);
            }
        }
    }

    std::cout << cnt;
}
