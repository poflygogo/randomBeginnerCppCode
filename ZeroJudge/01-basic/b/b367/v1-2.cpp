#include <iostream>
#include <vector>
using namespace std;

// 判斷是否可以符合翻轉180度不會改變的圖形
// 雙指針策略(二維版)
// 一個從左上(0, 0)開始
// 一個從右下(n-1, m-1)開始
bool Solve(const vector<vector<int>> &arr, int &n, int &m) {
    pair<int, int> lft = {0, 0};
    pair<int, int> rgt = {n - 1, m - 1};
    while (lft.first < rgt.first || lft.second < rgt.second) {
        if (arr[lft.first][lft.second] != arr[rgt.first][rgt.second]) {
            return false;
        }
        if (lft.second < m - 1) {
            lft.second++;
        } else {
            lft.first++;
            lft.second = 0;
        }
        if (rgt.second > 0) {
            rgt.second--;
        } else {
            rgt.first--;
            rgt.second = m - 1;
        }
    }
    return true;
}

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                cin >> arr[r][c];
            }
        }
        if (Solve(arr, n, m)) {
            cout << "go forward\n";
        } else {
            cout << "keep defending\n";
        }
    }
}
