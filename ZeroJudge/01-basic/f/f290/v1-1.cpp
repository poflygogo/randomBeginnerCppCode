#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> arr(n);
    for (std::pair<int, int> &item : arr)
    {
        std::cin >> item.second;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == n - 1)
        {
            arr[i].first = arr[i].second;
        }
        else
        {
            arr[i].first = arr[i - 1].second + arr[i + 1].second;
        }
    }
    std::sort(arr.begin(), arr.end());
    for (const std::pair<int, int> &item : arr)
    {
        std::cout << item.first << ' ' << item.second << '\n';
    }
}
