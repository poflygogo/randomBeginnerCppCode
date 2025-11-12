#include <array>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char id_num[9];
    scanf("%s", &id_num);
    char max1 = 0;
    char max2 = 0;
    for (char c : id_num)
    {
        if (c > max1)
        {
            max2 = max1;
            max1 = c;
        }
        else if (c > max2)
        {
            max2 = c;
        }
    }
    int a = max1 - '0';
    int b = max2 - '0';

    if (a * a + b * b == std::atoi(id_num + 6))
    {
        printf("Good Morning!");
    }
    else
    {
        printf("SPY!");
    }
}
