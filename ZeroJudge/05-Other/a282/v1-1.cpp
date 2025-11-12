#include <array>
#include <iostream>

constexpr int kLimit = 2002;
std::array<bool, kLimit> arr;

int main()
{
    int n, tmp;
    while (std::cin >> n)
    {
        arr.fill(true);
        for (int i = 0; i < n; i++)
        {
            std::cin >> tmp;
            arr[tmp] = false;
        }
        for (int i = 1; i < kLimit; i++)
        {
            if (arr[i])
            {
                std::cout << i << '\n';
                break;
            }
        }
    }
}
