#include <stdio.h>

int main()
{
    int size;
    long long num, pre = 0;
    scanf("%d", &size);
    while (size--)
    {
        scanf("%lld", &num);
        pre += num;
        printf("%lld ", pre);
    }
}
