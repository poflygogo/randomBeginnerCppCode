#include <cmath>
#include <iostream>

int main()
{
    int t, a, b;
    std::string op;
    std::cin >> t;
    while (t--)
    {
        std::cin >> a >> op >> b;
        if (op == "**")
        {
            std::cout << (int)std::pow(a, b) << '\n';
        }
        else if (op == "x")
        {
            std::cout << a * b << '\n';
        }
    }
}
