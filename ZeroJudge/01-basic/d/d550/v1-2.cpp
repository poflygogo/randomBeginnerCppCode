#include <algorithm>
#include <stdio.h>
#include <vector>
#define scan(x)                                                                                    \
    do                                                                                             \
    {                                                                                              \
        while ((x = getchar()) < '0')                                                              \
            ;                                                                                      \
        for (x -= '0'; '0' <= (c = getchar()); x = (x << 3) + (x << 1) + c - '0')                  \
            ;                                                                                      \
    } while (0)
char c;

int main()
{
    int n, m;
    scan(n);
    scan(m);
    std::vector<std::vector<int>> arr(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scan(arr[i][j]);
        }
    }
    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
