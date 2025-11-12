#include <cmath>
#include <stdio.h>

int main()
{
    long long int x1, y1, x2, y2, r;
    while (scanf("%lld %lld %lld %lld %lld", &x1, &y1, &x2, &y2, &r) != EOF)
    {
        if ((std::abs(x2 - x1) + std::abs(y2 - y1)) > r)
        {
            printf("alive\n");
        }
        else
        {
            printf("die\n");
        }
    }
}
