#include <array>
#include <iostream>
#include <vector>

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

            int flag = 0;
            int empty = 0;
            for (int i = r - (r > 0); i <= r + (r < rows - 1); i++)
            {
                for (int j = c - (c > 0); j <= c + (c < cols - 1); j++)
                {
                    if (graph[i][j] == 'P')
                    {
                        flag++;
                    }
                    else if (graph[i][j] == '#')
                    {
                        empty++;
                    }
                }
            }
            if ((flag == graph[r][c] - '0') && empty > 0)
            {
                graph[r][c] = 'O';
            }
        }
    }
    for (int i = 0; i < rows; i++)
    {
        std::cout << graph[i] << '\n';
    }
}
