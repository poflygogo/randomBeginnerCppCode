#include <iostream>
#include <map>

int main()
{
    int row, col, request;
    std::cin >> row >> col >> request;
    std::map<char, std::pair<int, int>> data;

    char tmp;
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            std::cin >> tmp;
            if (tmp != '0')
            {
                data.insert({tmp, {r, c}});
            }
        }
    }

    if (data.size() < request)
    {
        std::cout << "Mission fail.";
    }
    else
    {
        for (auto &&[_, d] : data)
        {
            if (request)
            {
                std::cout << d.first << ' ' << d.second << '\n';
                request--;
            }
            else
            {
                break;
            }
        }
    }
}
