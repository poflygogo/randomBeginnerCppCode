#include <iostream>

int main() {
    int n, k;
    while (std::cin >> n >> k) {
        int cnt = n;
        while (n >= k) {
            cnt += n / k;
            n = n / k + n % k;
        }
        std::cout << cnt << '\n';
    }
}
