#include <algorithm>
#include <stdio.h>
#include <vector>

int Solve(const std::vector<int> &arr, const int length)
{
    // 只有一格的土地沒資格種花
    if (length <= 1)
    {
        return 0;
    }

    // 家裡沒柵欄
    auto lft_i = std::find(arr.begin(), arr.end(), 1);
    auto rgt_i = std::find(arr.rbegin(), arr.rend(), 1);
    if (lft_i == arr.end() || rgt_i == arr.rend())
    {
        return 0;
    }

    // 只有一個柵欄，或有兩個柵欄但中間沒位置
    int lft = std::distance(arr.begin(), lft_i);
    int rgt = std::distance(arr.begin(), rgt_i.base()) - 1;
    if (rgt - 1 <= lft)
    {
        return 0;
    }

    // 經過以上步驟後，可以確保 lft 和 rgt 就是最外圍不同的兩根柵欄
    // 排除例外狀態後才開始計算有幾個位置合法
    int cnt = 0;
    for (int i = lft + 1; i < rgt; i++)
    {
        if (arr[i] == 9)
        {
            i++;
        }
        else if (arr[i] == 0 && arr[i - 1] != 9 && arr[i + 1] != 9)
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int n;
    scanf("%d", &n);
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("%d", Solve(arr, n));
}
