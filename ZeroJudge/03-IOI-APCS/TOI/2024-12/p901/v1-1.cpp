#include <algorithm>  // find
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> spices(n);
    for (size_t i = 0; i < n; i++) {
        cin >> spices[i];
    }

    int row, col;
    cin >> row >> col;

    vector<pair<int, int>> res(n, pair<int, int>{0, 0});
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            int t;
            cin >> t;
            auto it = find(spices.begin(), spices.end(), t);
            if (it != spices.end()) {
                res.at(distance(spices.begin(), it)) = {r + 1, c + 1};
            }
        }
    }

    for (auto&& i : res) {
        if (i.first) {
            cout << i.first << ' ' << i.second << '\n';
        } else {
            cout << "-1\n";
        }
    }
}
