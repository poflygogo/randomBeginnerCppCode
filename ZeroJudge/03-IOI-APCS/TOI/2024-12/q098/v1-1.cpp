#include <iostream>
#include <vector>

int main() {
    long long n;
    std::cin >> n;
    std::vector<int> factors;
    for (int p = 9; p > 1; p--) {
        while (n % p == 0) {
            n /= p;
            factors.push_back(p);
        }
    }

    if (n > 1) {
        std::cout << -1;
    } else {
        for (int i = factors.size() - 1; i >= 0; i--) {
            std::cout << factors[i] << (i == 0 ? '\n' : ' ');
        }
    }
}
