#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> spices(n);
    for (size_t i = 0; i < n; i++) {
        cin >> spices[i];
    }

    map<int, pair<int, int>> shelve;
    int max_row, max_col;
    cin >> max_row >> max_col;
    for (int r = 1; r <= max_row; r++) {
        for (int c = 1; c <= max_col; c++) {
            int t;
            cin >> t;
            shelve[t] = {r, c};
        }
    }

    for (size_t i = 0; i < spices.size(); i++) {
        auto it = shelve.find(spices[i]);
        if (it != shelve.end()) {
            cout << it->second.first << ' ' << it->second.second << '\n';
        } else {
            cout << "-1\n";
        }
    }
}
