#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<bool> counter(n + 1, false);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        counter[a] = !counter[a];
        counter[b] = !counter[b];
    }

    int odd_cnt = 0;
    for (int i = 0; i < counter.size(); i++) {
        odd_cnt += counter[i];
    }

    std::cout << (odd_cnt > 3 ? "NO" : "YES");
}
