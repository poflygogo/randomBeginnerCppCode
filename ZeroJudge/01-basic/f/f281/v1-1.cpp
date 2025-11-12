#include <algorithm>  // std::sort
#include <functional> // std::greater (c++11)
#include <stdio.h>
#include <vector>

int main()
{
    int c, light;
    scanf("%d", &c);
    std::vector<int> arr(c);
    for (int i = 0; i < c; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &light);
    std::sort(arr.begin(), arr.end(), std::greater<int>());

    int diff = light - arr.back();
    arr.pop_back();
    if (arr.back() - diff >= light)
    {
        printf("%d", diff);
    }
    else
    {
        printf("You are too black!");
    }
}
