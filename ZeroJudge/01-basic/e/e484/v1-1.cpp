#include <stdio.h>

bool IsPrime(int n)
{
    if (n == 1)
    {
        return false;
    }
    else if (n == 2 || n == 3)
    {
        return true;
    }
    else if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    else
    {
        for (int i = 5; i * i <= n; i += (i % 6 == 5 ? 2 : 4))
        {
            if (n % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf((IsPrime(n) ? "yes" : "no"));
}
