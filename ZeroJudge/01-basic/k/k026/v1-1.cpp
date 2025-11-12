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
    if (n % 2 == 0)
    {
        int sum = arr[n / 2] + arr[n / 2 - 1];
        if (sum % 2 == 0)
        {
            std::cout << sum / 2;
        }
        else
        {
            std::cout << sum / 2 << ".5";
        }
    }
    else
    {
        std::cout << arr[n / 2];
    }
}
