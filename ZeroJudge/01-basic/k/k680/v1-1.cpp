#include <iostream>

int main()
{
    int t;
    char op;
    int a, b;
    std::cin >> t;
    while (t--)
    {
        std::cin >> op >> a >> op >> b;
        if (op == '+')
        {
            std::cout << a + b << '\n';
        }
        else if (op == '-')
        {
            std::cout << a - b << '\n';
        }
    }
}
