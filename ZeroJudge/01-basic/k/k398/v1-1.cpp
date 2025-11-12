#include <array>
#include <iostream>
#include <vector>

int main()
{
    int rows, cols;
    std::cin >> rows >> cols;
    std::vector<std::string> graph(rows, std::string(cols, '.'));
    int curr_direction = 0;
    std::pair<int, int> curr = {0, 0};
    graph[0][0] = '*';
    std::cin.ignore();
    char c;
    while (std::cin.get(c) && std::isdigit(c))
    {
        int step = c - '0';
        switch (curr_direction)
        {
        case 0:
            while (step--)
            {
                if (curr.second < cols - 1)
                {
                    curr.second++;
                    graph[curr.first][curr.second] = '*';
                }
                else
                {
                    break;
                }
            }
            break;

        case 1:
            while (step--)
            {
                if (curr.first < rows - 1)
                {
                    curr.first++;
                    graph[curr.first][curr.second] = '*';
                }
                else
                {
                    break;
                }
            }
            break;

        case 2:
            while (step--)
            {
                if (curr.second > 0)
                {
                    curr.second--;
                    graph[curr.first][curr.second] = '*';
                }
                else
                {
                    break;
                }
            }
            break;

        case 3:
            while (step--)
            {
                if (curr.first > 0)
                {
                    curr.first--;
                    graph[curr.first][curr.second] = '*';
                }
                else
                {
                    break;
                }
            }
            break;

        default:
            break;
        }
        curr_direction = (curr_direction + 1) % 4;
    }

    for (auto &&line : graph)
    {
        std::cout << line << '\n';
    }
}
