#include <stdio.h>

int main()
{
    int size, num, pre = 0;
    scanf("%d", &size);
    while (size--)
    {
        scanf("%d", &num);
        printf("%d ", num - pre);
        pre = num;
    }
}
