#include <algorithm>
#include <array>
#include <stdio.h>
#include <utility>

int main()
{
    std::array<std::pair<int, int>, 3> arr;
    scanf("%d %d", &arr[0].first, &arr[0].second);
    scanf("%d %d", &arr[1].first, &arr[1].second);
    scanf("%d %d", &arr[2].first, &arr[2].second);
    std::sort(arr.begin(), arr.end());

    int num = arr[2].second;
    while (num % arr[0].first != arr[0].second || num % arr[1].first != arr[1].second)
    {
        num += arr[2].first;
    }
    printf("%d", num);
}
