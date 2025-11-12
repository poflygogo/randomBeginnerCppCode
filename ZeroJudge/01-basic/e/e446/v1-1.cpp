#include <algorithm>
#include <stdio.h>

const int kLimit = 10;
int arr[kLimit];

int main()
{
    // initialize
    for (int i = 0; i < kLimit; i++)
    {
        arr[i] = i + 1;
    }

    int n;
    scanf("%d", &n);
    do
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

    } while (std::next_permutation(arr, arr + n));
}
