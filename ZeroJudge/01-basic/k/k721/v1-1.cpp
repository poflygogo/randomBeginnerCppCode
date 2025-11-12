#include <iostream>

int main()
{
    int a, b;
    while (std::cin >> a >> b)
    {
        std::cout << (a <= b || a <= 0 ? "能" : "不能") << '\n';
    }
}
