#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long Gcd(long long a, long long b) { return !b ? a : Gcd(b, a % b); }

int main() {
    // std::cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> arr(n);
        for (size_t i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        long long diff = arr[1] - arr[0];
        for (size_t i = 2; i < n; i++) {
            diff = Gcd(diff, arr[i] - arr[i - 1]);
        }
        cout << diff << '\n';
    }
}
