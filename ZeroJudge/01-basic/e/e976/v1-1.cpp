#include <stdio.h>
#include <iostream>

int main()
{
    double a, b, c;
    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF)
    {
        printf("%.0lf %.0lf %.0lf. ", a, b, c);
        printf((b / c <= a ? "I will make it!\n" : "I will be late!\n"));
    }
}
