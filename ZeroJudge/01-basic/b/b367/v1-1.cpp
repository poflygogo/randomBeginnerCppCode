#include <iostream>
#include <vector>
using namespace std;

struct OffsetPair {
    int row;
    int col;
    int col_limit;

    // 重載 ++i 的算法
    OffsetPair &operator++() {
        if (col < col_limit - 1) {
            this->col += 1;
        } else {
            this->row += 1;
            this->col = 0;
        }
        return *this;
    }

    // 重載 --i 的算法
    OffsetPair &operator--() {
        if (col > 0) {
            this->col -= 1;
        } else {
            this->row -= 1;
            this->col = col_limit - 1;
        }
        return *this;
    }

    // 重載 < 運算子的算法
    bool operator<(const OffsetPair &other) { return row < other.row || col < other.col; }

    // 簡化取值的語法
    int get(const vector<vector<int>> &arr) { return arr[row][col]; }
};

// 判斷是否可以符合翻轉180度不會改變的圖形
// 雙指針策略(二維版)
// 一個從左上(0, 0)開始
// 一個從右下(n-1, m-1)開始
bool Solve(const vector<vector<int>> &arr, int &n, int &m) {
    OffsetPair lft = {0, 0, m};
    OffsetPair rgt = {n - 1, m - 1, m};
    while (lft < rgt) {
        if (lft.get(arr) != rgt.get(arr)) {
            return false;
        }
        ++lft;
        --rgt;
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
