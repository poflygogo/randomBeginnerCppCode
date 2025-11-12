#include <algorithm>
#include <iostream>
#include <vector>

using IHateThis = std::vector<std::pair<int, int>>;

IHateThis GetTime(int n)
{
    IHateThis arr;
    int a, b;
    while (n--)
    {
        std::cin >> a >> b;
        if (!arr.empty() && arr.back().second == a)
        {
            arr.back().second = b;
        }
        else
        {
            arr.push_back({a, b});
        }
    }
    return arr;
}

std::pair<int, int> Meeting(IHateThis &ming, IHateThis &awen, int d)
{
    if (ming.empty() || awen.empty())
    {
        return {-1, -1};
    }

    for (auto &&a : ming)
    {
        for (auto &&b : awen)
        {
            if (b.first > a.second)
            {
                break;
            }
            else if (b.second <= a.first)
            {
                continue;
            }
            else if (b.first <= a.first && a.first + d <= b.second)
            {
                return {a.first, a.first + d};
            }
            else if (a.first < b.first && b.first + d <= a.second)
            {
                return {b.first, b.first + d};
            }
        }
    }
    return {-1, -1};
}

int main()
{
    int n, m, d;
    std::cin >> n >> m;
    IHateThis ming = GetTime(n);
    IHateThis awen = GetTime(m);
    std::cin >> d;

    auto it = std::remove_if(ming.begin(), ming.end(),
                             [d](std::pair<int, int> &item) { return item.second - item.first < d; });
    ming.erase(it, ming.end());
    it = std::remove_if(awen.begin(), awen.end(),
                        [d](std::pair<int, int> &item) { return item.second - item.first < d; });
    awen.erase(it, awen.end());

    std::pair<int, int> res = Meeting(ming, awen, d);
    if (res.first != -1)
    {
        std::cout << res.first << ' ' << res.second;
    }
    else
    {
        std::cout << res.first;
    }
}
