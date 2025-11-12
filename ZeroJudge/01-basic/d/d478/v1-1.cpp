#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // --------------------------------
    // 不曉得有沒有不 IO 優化也能 AC 的作法......
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // --------------------------------
    
    // n    <- 幾組測資
    // size <- 陣列大小，每一組測資的陣列大小均相同
    // cnt  <- 統計重複元素個數
    // idx  <- 用於雙指針
    // tmp  <- 用於讀入每組測資的第二行陣列
    int n, size, cnt, idx, tmp;
    cin >> n >> size;
    vector<int> arr(size);
    while (n--)
    {
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        idx = 0;
        cnt = 0;
        for (int i = 0; i < size; i++)
        {
            cin >> tmp;
            while (idx < size && arr[idx] < tmp)
            {
                idx++;
            }
            if (idx >= size)
            {   // 就算已經肯定不可能會出現相同數字也要continue
                // 把數字讀完
                continue;;
            }
            else if (arr[idx] == tmp)
            {
                cnt++;
                idx++;
            }
        }
        cout << cnt << '\n';
    }
}
