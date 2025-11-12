#include <cmath>
#include <iostream>

std::pair<int, int> Snake(int n)
{
    int cycle = std::ceil(std::sqrt(n));
    int cycle_end_value = cycle * cycle;
    int cycle_mid_value = cycle_end_value - cycle + 1;
    std::pair<int, int> res;

    if (n == cycle_end_value)
    {
        res = {1, cycle};
    }
    else if (n == cycle_mid_value)
    {
        res = {cycle, cycle};
    }
    else if (n < cycle_mid_value)
    {
        res = {cycle, cycle - (cycle_mid_value - n)};
    }
    else
    {
        res = {cycle - (n - cycle_mid_value), cycle};
    }

    if (cycle % 2 == 0)
    {
        std::swap(res.first, res.second);
    }
    return res;
}

int main()
{
    int n;
    std::pair<int, int> res;
    while (std::cin >> n && n)
    {
        res = Snake(n);
        std::cout << res.first << ' ' << res.second << '\n';
    }
}
