#include <iostream>

int main()
{
    int t;
    int a, b, c;
    std::cin >> t;
    while (t--)
    {
        std::cin >> a;
        std::cin.ignore();
        std::cin >> b >> c;
        std::cout << (a + b == c ? "yes" : "no") << '\n';
    }
}
