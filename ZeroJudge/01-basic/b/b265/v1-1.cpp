#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        // 讀入資料並初步整理
        vector<vector<int>> arr(n, vector<int>(5, 0));
        for (vector<int> &line : arr) {
            cin >> line[0] >> line[1] >> line[2] >> line[3] >> line[4];
            sort(line.begin(), line.end());
        }

        // 排序，這樣元素相同的就會並列在一起
        // 然後用雙指針計算每個元素分別有幾個
        sort(arr.begin(), arr.end());
        vector<int> counter;
        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && arr[i] == arr[j]) {
                j++;
            }
            counter.push_back(j - i);
            i = j;
        }

        // 計算最熱門的課程(們)一共有多少人選擇
        int max_val = *max_element(counter.begin(), counter.end());
        int cnt = 0;
        for (const int &i : counter) {
            if (i == max_val) {
                cnt += max_val;
            }
        }
        cout << cnt << '\n';
    }
}
