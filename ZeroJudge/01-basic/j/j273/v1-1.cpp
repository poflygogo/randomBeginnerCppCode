#include <iostream>
#include <map>

int main()
{
    int n, k;
    std::map<int, int> data;
    std::cin >> n;
    while (n--)
    {
        std::cin >> k;
        data[k]++;
    }
    for (const std::pair<int, int> item : data)
    {
        std::cout << item.first << ' ' << item.second << '\n';
    }
}