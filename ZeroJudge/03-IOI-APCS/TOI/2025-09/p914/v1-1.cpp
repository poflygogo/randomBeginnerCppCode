#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int factors_sum = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            factors_sum += i;
            int t = n / i;
            if (i != t) {
                factors_sum += t;
            }
        }
    }

    std::cout << factors_sum << '\n' << (factors_sum == n ? "" : "not ") << "perfect";
}
