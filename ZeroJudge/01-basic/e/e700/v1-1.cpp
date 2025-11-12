#include <stdio.h>
#include <stdlib.h>

/*
水瓶座	1/21 ~ 2/19
雙魚座	2/20 ~ 3/20
牡羊座	3/21 ~ 4/20
金牛座	4/21 ~ 5/21
雙子座	5/22 ~ 6/21
巨蟹座	6/22 ~ 7/22
獅子座	7/23 ~ 8/21
處女座	8/22 ~ 9/23
天秤座	9/24 ~ 10/23
天蠍座	10/24 ~ 11/22
射手座	11/23 ~ 12/22
摩羯座	12/23 ~ 1/20
*/

int month, date;
char z;

void constellation(int);

int main(void)
{
    while (scanf("%d%c%d", &month, &z, &date) != EOF)
    {
        constellation(month * 100 + date);
    }
    return 0;
}

void constellation(int d)
{
    if (d >= 121 && d <= 219)
    {
        printf("水瓶座\n");
        return;
    }
    if (d >= 220 && d <= 320)
    {
        printf("雙魚座\n");
        return;
    }
    if (d >= 321 && d <= 420)
    {
        printf("牡羊座\n");
        return;
    }
    if (d >= 421 && d <= 521)
    {
        printf("金牛座\n");
        return;
    }
    if (d >= 522 && d <= 621)
    {
        printf("雙子座\n");
        return;
    }
    if (d >= 622 && d <= 722)
    {
        printf("巨蟹座\n");
        return;
    }
    if (d >= 723 && d <= 821)
    {
        printf("獅子座\n");
        return;
    }
    if (d >= 822 && d <= 923)
    {
        printf("處女座\n");
        return;
    }
    if (d >= 924 && d <= 1023)
    {
        printf("天秤座\n");
        return;
    }
    if (d >= 1024 && d <= 1122)
    {
        printf("天蠍座\n");
        return;
    }
    if (d >= 1123 && d <= 1222)
    {
        printf("射手座\n");
        return;
    }
    printf("摩羯座\n");
    return;
}
