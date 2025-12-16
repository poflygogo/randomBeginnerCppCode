// UVa 11351 - Last Man Standing
// ZeroJudge d192
// C++14

#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int case_id = 1; case_id <= t; ++case_id) {
        long long n, k;
        cin >> n >> k;

        // Josephus Problem
        long long ans = 0;
        for (long long i = 2 /* must start from 2*/; i <= n; ++i) { ans = (ans + k) % i; }

        cout << "Case " << case_id << ": " << ans + 1 /* 1-base */ << '\n';
    }
}
