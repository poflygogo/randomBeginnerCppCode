#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int n, k, q;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    while (k--)
    {
        std::cin >> q;
        auto res = std::lower_bound(arr.begin(), arr.end(), q);
        if (res == arr.end() || *res != q)
        {
            std::cout << "0\n";
        }
        else
        {
            std::cout << std::distance(arr.begin(), res) + 1 << '\n';
        }
    }
}
