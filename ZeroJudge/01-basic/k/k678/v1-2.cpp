#include <iostream>

int main()
{
    int t;
    int a, b, c;
    std::cin >> t;
    while (t--)
    {
        std::cin >> a >> b >> c;
        std::cout << (a + b == c ? "yes" : "no") << '\n';
    }
}
