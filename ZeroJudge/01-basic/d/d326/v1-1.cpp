#include <stdio.h>

/* set bit b to 1 */
int set_bit(int v, int b)
{
    v |= (1 << b);
    return v;
}

/* set bit b to 0 */
int unset_bit(int v, int b)
{
    v &= ~(1 << b);
    return v;
}

/* check_bit b is 1 or 0 */
int check_bit(int v, int a, int b)
{
    return bool(v & (1 << b));
}

int main(void)
{
    int i, v, bit, isSet;

    while (scanf("%d %d %d", &v, &bit, &isSet) == 3)
    {
        if (isSet)
            v = set_bit(v, bit);
        else
            v = unset_bit(v, bit);

        for (i = 31; i >= 0; --i)
            printf("%d", check_bit(v, 32, i));
        putchar('\n');
    }

    return 0;
}
