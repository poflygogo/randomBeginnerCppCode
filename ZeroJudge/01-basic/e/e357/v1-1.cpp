#include <stdio.h>

int F(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        return F(n / 2);
    }
    else
    {
        return F(n - 1) + F(n + 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", F(n));
}
