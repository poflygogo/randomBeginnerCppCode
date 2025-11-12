#include <algorithm>
#include <iostream>
#include <vector>

bool Compare(int a, int b)
{
    return std::abs(a) < std::abs(b);
}

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end(), Compare);
    int cnt = 0;
    for (int i = 1; i < size; i++)
    {
        if ((arr[i] > 0) ^ (arr[i - 1] > 0))
        {
            cnt++;
        }
    }
    std::cout << cnt;
}
