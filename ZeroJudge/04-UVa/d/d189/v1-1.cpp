// UVa 11150 - Cola
// ZeroJudge d189
// C++14

#include <iostream>

int main() {
    int n;
    while (std::cin >> n) {
        n += 1;
        int cnt = n - 1;
        while (n >= 3) {
            cnt += n / 3;
            n = n / 3 + n % 3;
        }
        std::cout << cnt << '\n';
    }
}
