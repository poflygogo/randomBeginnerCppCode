#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int test_case = 1;
    int n, m, k;
    while (cin >> n >> m >> k && n || m || k) {
        unordered_map<int, int> data;
        data.reserve(n);
        for (int i = 1; i <= n; i++) {
            int t;
            cin >> t;
            data[i] = t;
        }

        unordered_set<int> used;
        used.reserve(m);
        int cap_curr = 0;
        int cap_max = 0;
        for (size_t i = 0; i < m; i++) {
            int t;
            cin >> t;
            if (cap_max > k) {
                continue;
            }
            if (used.find(t) != used.end()) {
                cap_curr -= data.at(t);
                used.erase(t);
            } else {
                cap_curr += data.at(t);
                used.insert(t);
                cap_max = max(cap_max, cap_curr);
            }
        }

        if (test_case > 1) {
            cout << '\n';
        }
        cout << "Sequence " << test_case++ << '\n';
        if (cap_max > k) {
            cout << "Fuse was blown.\n";
        } else {
            cout << "Fuse was not blown.\nMaximal power consumption was " << cap_max
                 << " amperes.\n";
        }
    }
}
