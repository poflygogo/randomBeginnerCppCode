#include <stdio.h>

// 快速冪
long long int FastPow(long long int n, long long int exp, long long int mod)
{
    if (exp == 0)
    {
        return 1;
    }
    long long int ans = FastPow(n, exp / 2, mod);
    if (exp % 2 == 0)
    {
        return ans * ans % mod;
    }
    else
    {
        return ans * ans * n % mod;
    }
}

int main()
{
    long long int a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld", FastPow(a, b, 10007));
}
