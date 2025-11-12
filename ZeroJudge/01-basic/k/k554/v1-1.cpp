#include <iostream>
#include <vector>

int main()
{
    int rows, cols, val;
    std::cin >> rows >> cols;
    std::vector<std::vector<int>> graph(rows, std::vector<int>(cols, 0));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> val;
            switch (val)
            {
            case 1:
                graph[i][j] += 1;
                if (i > 0)
                {
                    graph[i - 1][j] += 1;
                }
                if (i != rows - 1)
                {
                    graph[i + 1][j] += 1;
                }
                if (j > 0)
                {
                    graph[i][j - 1] += 1;
                }
                if (j != cols - 1)
                {
                    graph[i][j + 1] += 1;
                }
                break;

            case 2:
                for (int k = 0; k < cols; k++)
                {
                    graph[i][k] += 1;
                }
                for (int k = 0; k < rows; k++)
                {
                    graph[k][j] += 1;
                }
                graph[i][j] -= 1;
                break;

            default:
                break;
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << graph[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
