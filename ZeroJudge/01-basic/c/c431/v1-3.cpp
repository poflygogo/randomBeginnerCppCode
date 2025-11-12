#include <array>
#include <iostream>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(c=getchar()); x=(x<<3)+(x<<1)+c-'0');}while(0)
char c;

int main()
{
    // --------------------------------
    // 不是很重要的 IO 優化......
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // --------------------------------

    int n;
    std::array<int, 101> arr;
    arr.fill(0);
    scan(arr[0]);
    while (arr[0]--)
    {
        scan(n);
        arr[n]++;
    }
    for (int i = 1; i < 101; i++)
    {
        while (arr[i] > 0)
        {
            std::cout << i << ' ';
            arr[i]--;
        }
    }
}
