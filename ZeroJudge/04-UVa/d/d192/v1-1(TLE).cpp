// UVa 11351 - Last Man Standing
// ZeroJudge d192
// C++14

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int test_case = 1; test_case <= t; ++test_case) {
        int n, k;
        cin >> n >> k;

        // brute force simulation
        vector<int> arr(n);
        iota(arr.begin(), arr.end(), 1);

        int curr_idx = 0;
        while (arr.size() > 1) {
            int next_idx = (curr_idx + k - 1) % arr.size();
            arr.erase(arr.begin() + next_idx);
            curr_idx = next_idx;
        }

        cout << "Case " << test_case << ": " << arr.front() << '\n';
    }
}
