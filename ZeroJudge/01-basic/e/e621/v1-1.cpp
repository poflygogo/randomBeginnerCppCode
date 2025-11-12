#include <stdio.h>

int main()
{
    int n, a, b, c;
    bool flag;
    scanf("%d", &n);
    while (n--)
    {
        flag = true;
        scanf("%d %d %d", &a, &b, &c);
        for (int i = a + 1; i < b; i++)
        {
            if (i % c != 0)
            {
                printf("%d ", i);
                flag = false;
            }
        }
        if (flag)
        {
            printf("No free parking spaces.\n");
        }
        else
        {
            printf("\n");
        }
    }
}
