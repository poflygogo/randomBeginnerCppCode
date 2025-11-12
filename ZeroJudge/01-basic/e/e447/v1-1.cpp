#include <queue>
#include <stdio.h>

int main()
{
    int n, k;
    std::queue<int> arr;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &k);
        switch (k)
        {
        case 1:
            scanf("%d", &k);
            arr.push(k);
            break;
        case 2:
            printf("%d\n", (arr.empty() ? -1 : arr.front()));
            break;
        case 3:
            if (!arr.empty())
            {
                arr.pop();
            }
            break;
        default:
            printf("should not happen...\n");
            return 0;
        }
    }
}
