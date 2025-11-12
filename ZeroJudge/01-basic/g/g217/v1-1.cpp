#include <iostream>
#include <map>

int main() {
    int t, n, k;
    std::map<int, int> counter;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        counter.clear();
        for (int i = 0; i < n; i++) {
            std::cin >> k;
            counter[k]++;
        }
        int max_val = 0;
        for (const std::pair<int, int> &item : counter) {
            if (max_val < item.second) {
                max_val = item.second;
            }
        }
        std::cout << (max_val <= n / 2 ? "Yes" : "No") << '\n';
    }
}
