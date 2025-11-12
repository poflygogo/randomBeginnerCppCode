#include <iostream>
#include <vector>
using namespace std;

// 判斷是否可以符合翻轉180度不會改變的圖形
// 雙指針策略(一維版)
bool Solve(const vector<int> &arr, int &n, int &m) {
    int lft = 0;
    int rgt = n * m - 1;
    while (lft < rgt) {
        if (arr[lft++] != arr[rgt--]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> arr(n * m);
        for (int i = 0, j = n * m; i < j; i++) {
            cin >> arr[i];
        }

        if (Solve(arr, n, m)) {
            cout << "go forward\n";
        } else {
            cout << "keep defending\n";
        }
    }
}
