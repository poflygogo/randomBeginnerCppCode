#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // --------------------------------
    // 不是很重要的 IO 優化......
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // --------------------------------
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int num : arr)
    {
        cout << num << ' ';
    }
    cout << '\n';
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == 0 || arr[i] != arr[i - 1])
        {
            cout << arr[i] << ' ';
        }
    }
    cout << '\n';
}
