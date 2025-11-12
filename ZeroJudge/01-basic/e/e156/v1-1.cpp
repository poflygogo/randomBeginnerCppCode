#include <stdio.h>

int sum(int n, int res = 0)
{
    if (n)
    {
        return sum(n - 1, res + n);
    }
    else
    {
        return res;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", sum(n));
}
