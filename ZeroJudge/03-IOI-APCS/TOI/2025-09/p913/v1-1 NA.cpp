#include <iostream>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    int val = n;
    do {
        std::cout << val << '\n';
        val *= n;
    } while (val <= m);
}
