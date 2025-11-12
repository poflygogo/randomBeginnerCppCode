#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> counter(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        counter[a]++;
        counter[b]++;
    }

    int odd_cnt = 0;
    for (int i = 0; i < counter.size(); i++) {
        if (counter[i] % 2 != 0) {
            odd_cnt++;
        }
    }

    std::cout << (odd_cnt > 3 ? "NO" : "YES");
}
