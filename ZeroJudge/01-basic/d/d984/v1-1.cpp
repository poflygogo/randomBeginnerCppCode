#include <algorithm>
#include <array>
#include <iostream>

int main()
{
    std::array<std::pair<int, char>, 3> arr;
    while (std::cin >> arr[0].first >> arr[1].first >> arr[2].first)
    {
        arr[0].second = 'A';
        arr[1].second = 'B';
        arr[2].second = 'C';
        std::sort(arr.begin(), arr.end());
        std::cout << (arr[1].first > arr[2].first - arr[0].first ? arr[1].second : arr[2].second)
                  << '\n';
    }
}
