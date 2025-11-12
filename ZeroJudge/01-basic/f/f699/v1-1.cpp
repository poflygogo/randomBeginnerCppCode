#include <array>
#include <iostream>
#include <queue>
#include <vector>

int main()
{
    int row_limit, col_limit;
    std::cin >> row_limit >> col_limit;
    std::vector<std::vector<int>> graph(row_limit, std::vector<int>(col_limit));
    std::vector<std::vector<int>> step(row_limit, std::vector<int>(col_limit, 0));
    for (int i = 0; i < row_limit; i++)
    {
        for (int j = 0; j < col_limit; j++)
        {
            std::cin >> graph[i][j];
        }
    }

    bool flag = true;
    constexpr std::array<std::pair<int, int>, 4> directions = {{{-1, 0}, {0, -1}, {0, 1}, {1, 0}}};
    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        std::pair<int, int> curr = q.front();
        q.pop();
        if (graph[curr.first][curr.second] == 1)
        {
            std::cout << step[curr.first][curr.second] << '\n';
            flag = false;
        }
        for (auto &&d : directions)
        {
            int nr = curr.first + d.first;
            int nc = curr.second + d.second;
            if (0 <= nr && nr < row_limit && 0 <= nc && nc < col_limit && step[nr][nc] == 0 &&
                graph[nr][nc] != 2)
            {
                step[nr][nc] = step[curr.first][curr.second] + 1;
                q.push({nr, nc});
            }
        }
    }
    if (flag)
    {
        std::cout << "嘉油！";
    }
}
