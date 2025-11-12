#include <array>
#include <iostream>

const int kLimit = 93;
std::array<long long, kLimit> fib;

int GCD(int num1, int num2)
{
    if (num2 == 0)
    {
        return num1;
    }

    return GCD(num2, num1 % num2);
}

int main()
{
    // initialize
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < kLimit; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    int a, b;
    while (std::cin >> a >> b)
    {
        std::cout << fib[GCD(a, b) - 1] << '\n';
    }
}
