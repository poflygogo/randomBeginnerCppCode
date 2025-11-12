#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 不是很重要的 IO 優化......
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, lft, rgt;
    while (cin >> n >> m) {
        std::vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }
        for (int i = 0; i < m; i++) {
            cin >> lft >> rgt;
            cout << arr[rgt] - arr[lft - 1] << '\n';
        }
    }
}
