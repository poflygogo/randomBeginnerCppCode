#include <algorithm>
#include <array>
#include <iostream>

const int kLimit = 10;
std::array<int, kLimit> arr;

std::string ArrToStr(const int n)
{
    std::string s;
    for (int i = 0; i < n; i++)
    {
        s += std::to_string(arr[i]);
        s += ' ';
    }
    s.back() = '\n';
    return s;
}

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
        std::cout << ArrToStr(n);
    } while (std::next_permutation(arr.begin(), arr.begin() + n));
}
