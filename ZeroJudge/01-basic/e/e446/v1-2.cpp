#include <algorithm>
#include <array>
#include <iostream>

const int kLimit = 10;
std::array<int, kLimit> arr;

int main()
{
    // initialize
    for (int i = 0; i < kLimit; i++)
    {
        arr[i] = i + 1;
    }

    // --------------------------------
    // 不是很重要的 IO 優化......
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // --------------------------------

    int n;
    std::cin >> n;
    do
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << arr[i] << ' ';
        }
        std::cout << '\n';

    } while (std::next_permutation(arr.begin(), arr.begin() + n));
}
