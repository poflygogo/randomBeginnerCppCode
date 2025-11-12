#include <algorithm>
#include <iostream>
#include <vector>

int Bisect(const std::vector<int> &arr, int target)
{
    int lft = 0;
    int rgt = arr.size();
    int mid;
    while (lft < rgt)
    {
        mid = (lft + rgt) / 2;
        if (arr[mid] == target)
        {
            return mid + 1;
        }
        else if (arr[mid] < target)
        {
            lft = mid + 1;
        }
        else
        {
            rgt = mid;
        }
    }
    return 0;
}

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
        std::cout << Bisect(arr, q) << '\n';
    }
}
