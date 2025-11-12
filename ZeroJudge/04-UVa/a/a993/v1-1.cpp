#include <iostream>

int main() {
    int n;
    while (std::cin >> n) {
        int cnt = 1;
        int ones = 1;
        while (ones % n != 0) {
            ones = (ones * 10 + 1) % n;
            cnt++;
        }
        std::cout << cnt << '\n';
    }
}
