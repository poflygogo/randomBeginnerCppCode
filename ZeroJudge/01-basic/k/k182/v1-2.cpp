#include <cmath>
#include <iostream>

int main()
{
    int n, k;
    int sum = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> k;
        sum += k;
    }
    std::string res = std::to_string(std::round((double)(sum * 100) / (double)n) / 100.0);
    int i = res.find('.');
    res.erase(res.find('0', i), res.size());
    if (res.back() == '.')
    {
        res.pop_back();
    }

    std::cout << res;
}
