#include <iostream>

int pow(int a, int b)
{
    int res = 1;
    while (b--)
    {
        res *= a;
    }
    return res;
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << a << '^' << b << " = " << pow(a, b);
}
