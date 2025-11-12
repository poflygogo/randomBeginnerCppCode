#include <iostream>

long long NthFib(long long n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }

    long long prev1 = 0;
    long long prev2 = 1;
    long long t;
    n -= 2;
    while (n--)
    {
        t = prev2;
        prev2 += prev1;
        prev1 = t;
    }
    return prev2;
}

int main()
{
    long long n;
    std::cin >> n;
    std::cout << NthFib(n);
}
