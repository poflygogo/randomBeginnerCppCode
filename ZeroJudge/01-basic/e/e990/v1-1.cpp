#include <cmath>
#include <stdio.h>

int main()
{
    double t, n;
    while (scanf("%lf %lf", &t, &n) != EOF)
    {
        printf("%.3f\n", -t * log2(n));
    }
}
