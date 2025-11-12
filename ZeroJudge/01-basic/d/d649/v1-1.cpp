#include <iostream>

int main()
{
    int n;
    while (std::cin >> n && n)
    {
        for (int i = 1; i <= n; i++)
        {
            std::cout << std::string(n - i, '_') << std::string(i, '+') << '\n';
        }
        std::cout << '\n';
    }
}
