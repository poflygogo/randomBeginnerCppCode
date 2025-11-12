#include <array>
#include <stdio.h>

int main()
{
    int n;
    std::array<int, 101> arr;
    arr.fill(0);
    scanf("%d", &arr[0]);
    while (arr[0]--)
    {
        scanf("%d", &n);
        arr[n]++;
    }
    for (int i = 1; i < 101; i++)
    {
        while (arr[i] > 0)
        {
            printf("%d ", i);
            arr[i]--;
        }
    }
}
