#include <iostream>
#include <vector>

using namespace std;

int main() {
    int test_case = 1;
    int n, m, k;
    while (cin >> n >> m >> k && n || m || k) {
        vector<int> data(n);
        for (size_t i = 0; i < n; i++) {
            cin >> data[i];
        }

        vector<char> used(n, 0);
        int cap_curr = 0;
        int cap_max = 0;
        for (size_t i = 0; i < m; i++) {
            int t;
            cin >> t;
            if (cap_max > k) {
                continue;
            }
            if (used[t - 1]) {
                cap_curr -= data[t - 1];
                used[t - 1] = 0;
            } else {
                cap_curr += data[t - 1];
                used[t - 1] = true;
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
