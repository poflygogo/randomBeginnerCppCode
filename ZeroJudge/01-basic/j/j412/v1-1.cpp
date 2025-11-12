#include <iostream>
#include <set>
#include <vector>

int main()
{
    int rows, cols, total_hole;
    std::cin >> rows >> cols >> total_hole;
    std::set<std::pair<int, int>> holes;
    std::pair<int, int> item;
    for (int i = 0; i < total_hole; i++)
    {
        std::cin >> item.first >> item.second;
        holes.insert(item);
    }

    std::vector<std::vector<int>> dp(rows + 1, std::vector<int>(cols + 1, 0));
    dp[1][1] = 1;
    dp[0][2 % cols] = 1;
    dp[2 % rows][0] = 1;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= cols; j++)
        {
            if (holes.find({i, j}) != holes.end())
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    std::cout << dp[rows][cols];
}
