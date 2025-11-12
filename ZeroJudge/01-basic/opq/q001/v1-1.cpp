#include <iostream>

long long cycle421(long long n, int cnt = 0) {
    if (n == 4) {
        return cnt;
    } else if (n % 2 == 0) {
        return cycle421(n / 2, cnt + 1);
    } else {
        return cycle421(n * 3 + 1, cnt + 1);
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    long long n;
    while (std::cin >> n) {
        std::cout << cycle421(n) << '\n';
    }
}
