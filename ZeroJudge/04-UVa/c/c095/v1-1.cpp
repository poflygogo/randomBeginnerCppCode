#include <algorithm>  // find
#include <iostream>
#include <vector>

using namespace std;

struct Test {
    vector<int> lft;
    vector<int> rgt;
    char flag;
};

bool IsPossible(const vector<Test>& tests, int coin_id, int status) {
    for (auto&& t : tests) {
        int w_lft = status * (find(t.lft.begin(), t.lft.end(), coin_id) != t.lft.end());
        int w_rgt = status * (find(t.rgt.begin(), t.rgt.end(), coin_id) != t.rgt.end());
        char res = (w_lft < w_rgt ? -1 : (w_lft > w_rgt));
        if (res != t.flag) {
            return false;
        }
    }
    return true;
}

// Hint: 輸出 0 的條件除了找不到匹配值外，有多個硬幣可能為假時，也應輸出 0
int solve(const vector<Test>& tests, const int total_num) {
    int res = 0;
    for (int i = 1; i <= total_num; i++) {  // 直接窮舉
        if (IsPossible(tests, i, -1)) {
            if (res) {
                return 0;
            } else {
                res = i;
            }
        } else if (IsPossible(tests, i, 1)) {
            if (res) {
                return 0;
            } else {
                res = i;
            }
        }
    }
    return res;
}

int main() {
    int m;
    cin >> m;
    for (int cnt = 0; cnt < m; cnt++) {
        int n, k;
        cin >> n >> k;
        vector<Test> tests(k);
        for (size_t i = 0; i < k; i++) {
            int p;
            cin >> p;
            tests[i].rgt.resize(p);
            tests[i].lft.resize(p);
            for (size_t j = 0; j < p; j++) {
                cin >> tests[i].lft[j];
            }
            for (size_t j = 0; j < p; j++) {
                cin >> tests[i].rgt[j];
            }
            cin >> tests[i].flag;
            tests[i].flag = (tests[i].flag == '<' ? -1 : (tests[i].flag == '>'));
        }

        if (cnt > 0) {
            cout << '\n';
        }
        cout << solve(tests, n) << '\n';
    }
}
