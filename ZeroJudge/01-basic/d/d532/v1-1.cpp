#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    a -= 1;
    a = (a / 4 - a / 100 + a / 400);
    b = (b / 4 - b / 100 + b / 400);
    printf("%d", b - a);
}
