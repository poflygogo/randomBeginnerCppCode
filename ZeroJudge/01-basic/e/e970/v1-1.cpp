#include <stdio.h>
#include <vector>

int main()
{
    int n;
    scanf("%d", &n);
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i += arr.back())
    {
        sum += arr[i];
    }
    sum %= n;
    printf("%d %d", (sum ? sum : n), arr[(n + sum - 1) % n]);
}
