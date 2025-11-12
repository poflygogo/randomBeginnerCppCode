#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        int s = a + b;
        int res = 0;
        while (s >= c) {
            res += s / c;
            s = s / c + s % c;
        }
        std::cout << res << '\n';
    }
}
