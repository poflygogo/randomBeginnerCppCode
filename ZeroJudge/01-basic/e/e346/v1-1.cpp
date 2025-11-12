#include <stdio.h>
#include <vector>

int main()
{
    int n, q, lft, rgt;
    scanf("%d", &n);
    std::vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
        if (i > 0)
        {
            arr[i] += arr[i - 1];
        }
    }
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d %d", &lft, &rgt);
        printf("%lld\n", arr[rgt - 1] - (lft - 2 >= 0 ? arr[lft - 2] : 0));
    }
}
