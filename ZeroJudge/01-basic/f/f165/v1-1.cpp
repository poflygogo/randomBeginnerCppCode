#include <stdio.h>

int main()
{
    int candy, kid;
    scanf("%d %d", &candy, &kid);
    if (kid == 0 || candy % kid == 0)
    {
        printf("OK!");
    }
    else
    {
        printf("%d", candy % kid);
    }
}
