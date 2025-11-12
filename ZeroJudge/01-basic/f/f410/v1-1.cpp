#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int n, tmp;
    std::cin >> n;
    std::vector<int> even, odd;
    even.reserve(n);
    odd.reserve(n);
    while (n--)
    {
        std::cin >> tmp;
        if (tmp % 2 == 0)
        {
            even.push_back(tmp);
        }
        else
        {
            odd.push_back(tmp);
        }
    }
    std::sort(even.begin(), even.end());
    std::sort(odd.begin(), odd.end(), std::greater<int>());
    for (int i : even)
    {
        std::cout << i << ' ';
    }
    for (int i : odd)
    {
        std::cout << i << ' ';
    }
}
