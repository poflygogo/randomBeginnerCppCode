#include <stdio.h>

int main()
{
    int king_slime, slime;
    int day = 0;
    scanf("%d %d", &king_slime, &slime);
    while ((king_slime + slime) / king_slime != 1 << day)
    {
        day++;
    }
    printf("%d", day);
}
