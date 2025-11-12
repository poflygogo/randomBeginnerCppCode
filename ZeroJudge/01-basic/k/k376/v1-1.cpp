#include <iostream>

bool LargestPrimeFactorHelper(int &n, const int p)
{
    bool flag = n % p == 0;
    while (n % p == 0)
    {
        n /= p;
    }
    return flag;
}

int LargestPrimeFactor(int n)
{
    int res = 1;
    if (LargestPrimeFactorHelper(n, 2))
    {
        res = 2;
    }
    if (LargestPrimeFactorHelper(n, 3))
    {
        res = 3;
    }
    for (int i = 5; i * i < n; i += (i % 6 == 1 ? 4 : 2))
    {
        if (LargestPrimeFactorHelper(n, i))
        {
            res = i;
        }
    }
    return std::max(res, n);
}

int main()
{
    int n, num;
    int res = 0;
    int res_factor = 0;
    std::cin >> n;
    while (n--)
    {
        std::cin >> num;
        int fac = LargestPrimeFactor(num);
        if (fac > res_factor || (fac == res_factor && num > res))
        {
            res = num;
            res_factor = fac;
        }
    }

    std::cout << res;
}
