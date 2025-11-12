#include <stdio.h>

int main()
{
    int n, s;
    while (scanf("%d", &n) != EOF)
    {
        while (n > 0)
        {
            s = n & 1;
            n >>= 1;
            n = n - s;
        }
        if (n == 0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}
