#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>

int main() {
    int n;
    while (std::cin >> n) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        std::set<int> diff;
        for (size_t i = 1; i < n; ++i) {
            int d = abs(arr[i] - arr[i - 1]);
            if (1 <= d && d <= n) {
                diff.insert(d);
            }
        }
        std::cout << (diff.size() == n - 1 ? "Jolly" : "Not jolly") << '\n';
    }
}
