#include <stdio.h>

int main()
{
    int type, level;
    while (scanf("%d %d", &type, &level) != EOF)
    {
        if (type == 0)
        {
            printf("0\n");
        }
        else
        {
            int res = 0;
            res += (level >= 120) * 3;
            res += (level >= 70);
            res += (level >= 30);
            res += (type == 2 && level >= 8);
            res += (type != 2 && level >= 10);
            if (type == 2)
            {
                res += (level > 8 ? (level - 8) * 3 : 0);
            }
            else
            {
                res += (level > 10 ? (level - 10) * 3 : 0);
            }
            printf("%d\n", res);
        }
    }
}
