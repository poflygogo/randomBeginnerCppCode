#include <algorithm>
#include <array>
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    const int size = 5;
    int n;
    array<int, size> arr = {0};
    while (cin >> n && n) {
        unordered_map<long long, int> counter;
        counter.reserve(n); // 預先確認最多可能要放幾個元素

        // array<int, size> 本身是不可哈希的，標準庫沒有實現它的哈希算法，所以我們需要自己實現
        // 但自己寫很麻煩，所以這邊把傳入的數字前後相連，變成一個很大的 15 位數字
        // 直接用標準庫的 lone lone int 的哈希算法幫我們處理就好
        // 其實也可以用 string，這部分就看個人
        // 
        // 可以這樣做是因為題目保證所有數字都介於 100 到 499 之間
        for (int i = 0; i < n; i++) {
            cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
            sort(arr.begin(), arr.end());
            long long tmp = 0;
            for (const int &num : arr) {
                tmp = tmp * 1000 + num;
            }
            counter[tmp] += 1;
        }

        int max_val = 0;
        for (const pair<long long, int> &item : counter) {
            max_val = max(max_val, item.second);
        }
        int cnt = 0;
        for (const pair<long long, int> &item : counter) {
            cnt += (item.second == max_val) * max_val;
        }
        cout << cnt << '\n';
    }
}
