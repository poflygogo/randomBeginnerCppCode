#include <stdio.h>

int counter[4];

int main()
{
    int n, t;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &t);
        counter[t]++;
    }
    for (int i = 1; i < 4; i++)
    {
        while (counter[i]--)
        {
            printf("%d ", i);
        }
    }
}
