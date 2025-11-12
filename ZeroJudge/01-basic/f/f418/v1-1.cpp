#include <iostream>
#include <vector>

int main()
{
    int rows, cols, r1, c1, r2, c2;
    std::cin >> rows >> cols >> r1 >> c1 >> r2 >> c2;
    std::vector<std::string> graph(rows);
    for (int i = 0; i < rows; i++)
    {
        std::cin >> graph[i];
    }
    int dr = (r1 < r2 ? 1 : (r1 > r2 ? -1 : 0));
    int dc = (c1 < c2 ? 1 : (c1 > c2 ? -1 : 0));
    r1--;
    r2--;
    c1--;
    c2--;
    for (int i = r1, j = c1; i != r2 || j != c2; i += dr, j += dc)
    {
        std::cout << graph[i][j];
    }
    std::cout << graph[r2][c2];
}
