#include <stdio.h>

const int kLimit = 2781668;
const int kmod = 10007;
int dp[kLimit + 1];

int main()
{
    // initialize
    dp[0] = 1;
    dp[1] = 3;
    dp[2] = 5;
    dp[3] = 9;
    for (int i = 4; i <= kLimit; i++)
    {
        dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % kmod;
    }
    int n;
    scanf("%d", &n);
    if (n < 4)
    {
        printf("1");
    }
    else
    {
        printf("%d", dp[(n - 3) % kLimit]);
    }
}
