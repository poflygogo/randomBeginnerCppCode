#include <climits>
#include <stdio.h>

int main()
{
    int pokemon, sand, cp, iv;
    scanf("%d %d", &pokemon, &sand);
    sand /= 1000;

    int res = INT_MIN;
    int res_id = 1;
    for (int i = 1; i <= pokemon; i++)
    {
        scanf("%d %d", &cp, &iv);
        if (iv < 30)
        {
            cp += sand * 10;
        }
        else if (iv < 40)
        {
            cp += sand * 50;
        }
        else
        {
            cp += sand * 100;
        }
        if (cp > res)
        {
            res = cp;
            res_id = i;
        }
    }
    printf("%d %d", res_id, res);
}
