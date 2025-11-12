#include <array>
#include <iostream>
#include <map>
#include <set>
#include <vector>

int main()
{
    int row_limit, col_limit;
    std::cin >> row_limit >> col_limit;
    std::vector<std::vector<char>> graph(row_limit, std::vector<char>(col_limit, '0'));
    std::set<std::pair<int, int>> bombs;
    std::map<std::pair<int, int>, bool> detectors;

    // 定義偵測器相互失效判定的方向（左上、上、右上、左）
    const std::array<std::pair<int, int>, 4> check = {{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}}};
    // 八連通方向
    const std::array<std::pair<int, int>, 8> directions = {{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};
    // 讀圖、記錄炸彈與偵測器，並判定偵測器是否失效
    for (int i = 0; i < row_limit; i++)
    {
        for (int j = 0; j < col_limit; j++)
        {
            std::cin >> graph[i][j];
            switch (graph[i][j])
            {
            case '1':
                bombs.insert({i, j});
                break;
            case '5':
                detectors.insert({{i, j}, true});

                for (auto &&d : check)
                {
                    int r = i + d.first;
                    int c = j + d.second;
                    if (r >= 0 && c >= 0 && c < col_limit &&
                        detectors.find({r, c}) != detectors.end())
                    {
                        detectors[{i, j}] = false;
                        detectors[{r, c}] = false;
                    }
                }
                break;
            default:
                break;
            }
        }
    }

    // 統計每顆炸彈是否被鄰格有效偵測器覆蓋
    int cnt = 0;
    for (auto &&b : bombs)
    {
        for (auto &&d : directions)
        {
            int r = b.first + d.first;
            int c = b.second + d.second;
            if (detectors.find({r, c}) != detectors.end() && detectors[{r, c}])
            {
                cnt++;
                break;
            }
        }
    }
    std::cout << cnt << ' ' << bombs.size() - cnt;
}
