#include <iostream>

int main()
{
    long long t, health, a, b;
    std::cin >> t;
    while (t--)
    {
        std::cin >> health >> a >> b;
        std::cout << health + a * b << '\n';
    }
}
