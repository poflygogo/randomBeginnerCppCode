#include <iostream>
#include <string>
#include <vector>

void dfs(std::vector<std::string> &graph, int limit, int row, int col)
{
    if (row < 0 | row >= limit || col < 0 || col >= limit || graph[row][col] == '+')
    {
        return;
    }
    graph[row][col] = '+';
    dfs(graph, limit, row + 1, col);
    dfs(graph, limit, row - 1, col);
    dfs(graph, limit, row, col + 1);
    dfs(graph, limit, row, col - 1);
}

int main()
{
    int n, row, col;
    std::cin >> n;
    std::vector<std::string> graph(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> graph[i];
    }
    std::cin >> row >> col;
    dfs(graph, n, row, col);
    for (const std::string s : graph)
    {
        std::cout << s << '\n';
    }
}
