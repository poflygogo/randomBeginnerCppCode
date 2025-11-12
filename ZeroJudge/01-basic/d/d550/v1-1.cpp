#include <algorithm>
#include <stdio.h>
#include <vector>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    std::vector<std::vector<int>> arr(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
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
