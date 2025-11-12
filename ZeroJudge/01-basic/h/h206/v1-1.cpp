#include <iostream>
#include <vector>

int Solve(std::vector<int> arr, int lft, int rgt, bool flag = true)
{
    if (lft == rgt)
    {
        return arr[lft];
    }
    int size = (rgt - lft + 1) / 2;
    if (flag)
    {
        return std::max(Solve(arr, lft, lft + size - 1, false), Solve(arr, lft + size, rgt, false));
    }
    else
    {
        return std::min(Solve(arr, lft, lft + size - 1, true), Solve(arr, lft + size, rgt, true));
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::cout << Solve(arr, 0, n - 1);
}
