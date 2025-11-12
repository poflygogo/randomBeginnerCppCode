#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int n;
    while (std::cin >> n)
    {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> arr[i];
        }
        std::sort(arr.begin(), arr.end());
        for (int num : arr)
        {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }
}
