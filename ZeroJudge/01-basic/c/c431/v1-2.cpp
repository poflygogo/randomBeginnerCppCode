#include <array>
#include <iostream>

int main()
{
    // --------------------------------
    // 不是很重要的 IO 優化......
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // --------------------------------

    int n;
    std::array<int, 101> arr;
    arr.fill(0);
    std::cin >> arr[0];
    while (arr[0]--)
    {
        std::cin >> n;
        arr[n]++;
    }
    for (int i = 1; i < 101; i++)
    {
        while (arr[i] > 0)
        {
            std::cout << i << ' ';
            arr[i]--;
        }
    }
}
