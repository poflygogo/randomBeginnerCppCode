#include <stdio.h>

int nums[100001];

int main()
{
    int n, id, cnt, p;
    while (scanf("%d", &n) != EOF)
    {
        while (n--)
        {
            scanf("%d %d", &id, &cnt);
            while (cnt--)
            {
                scanf("%d", &p);
                nums[p] = id;
            }
        }
        scanf("%d", &p);
        printf("%d\n", nums[p]);
    }
}
