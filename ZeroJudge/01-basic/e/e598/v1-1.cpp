#include <stdio.h>

bool IsGood(int n)
{
    if (n < 200000000)
    {
        return true;
    }
    for (int i = 2; i < 10; i++)
    {
        if (n % i == 0 && 100000000 <= n / i && n / i < 999999999)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf((IsGood(n) ? "yes" : "no"));
}
