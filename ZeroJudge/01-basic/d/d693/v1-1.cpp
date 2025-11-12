#include <iostream>

long long GCD(long long a, long long b)
{
    return b == 0 ? a : GCD(b, a % b);
}

long long LCM(long long a, long long b)
{
    return a * b / GCD(a, b);
}

int main()
{
    long long n, num1, num2;
    while (std::cin >> n && n)
    {
        n--;
        std::cin >> num1;
        while (n--)
        {
            std::cin >> num2;
            num1 = LCM(num1, num2);
        }
        std::cout << num1 << '\n';
    }
}
