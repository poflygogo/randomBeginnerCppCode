#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n % 9 != 0 || n == 0)
        {
            printf("%d\n", n % 9);
        }
        else
        {
            printf("9\n");
        }
    }
}
