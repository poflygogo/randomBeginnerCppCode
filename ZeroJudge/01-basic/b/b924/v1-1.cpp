#include <iostream>
#include <vector>
using namespace std;

bool IsPossible(const vector<int> arr) {
    int is_odd = 0;
    int idx = 0;
    while (is_odd <= 2 && idx < arr.size()) {
        is_odd += arr[idx] % 2;
        idx += 1;
    }
    return is_odd == 0 || is_odd == 2;
}

int main() {
    int n, m, a, b;
    scanf("%d %d\n", &n, &m);
    vector<int> counter(n + 1, 0);
    while (m--) {
        scanf("%d %d\n", &a, &b);
        counter[a] += 1;
        counter[b] += 1;
    }
    cout << (IsPossible(counter) ? "YES" : "NO") << endl;
}
