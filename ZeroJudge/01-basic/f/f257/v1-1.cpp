#include <array>
#include <iostream>
#include <vector>

int main()
{
    int n, k, r, c;
    while (std::cin >> n >> k)
    {
        std::vector<std::string> matrix(n, std::string(n, '0'));

        while (k--)
        {
            std::cin >> c >> r;
            matrix[r][c] = 'x';
        }

        constexpr std::array<std::pair<int, int>, 8> directions = {
            {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 'x')
                {
                    continue;
                }

                int sum = 0;
                for (const std::pair<int, int> &d : directions)
                {
                    int nr = i + d.first;
                    int nc = j + d.second;
                    sum += (0 <= nr && nr < n && 0 <= nc && nc < n && matrix[nr][nc] == 'x');
                }
                if (sum)
                {
                    matrix[i][j] = '0' + sum;
                }
            }
        }

        for (const std::string s : matrix)
        {
            std::cout << s << '\n';
        }
    }
}
