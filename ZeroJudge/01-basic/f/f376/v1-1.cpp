#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    std::cout << arr[n / 2 - (n % 2 == 0)];
}
