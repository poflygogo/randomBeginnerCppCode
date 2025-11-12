#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

std::vector<int> Sieve() {
    constexpr int kLimit = 1000000;
    std::bitset<kLimit> is_prime;
    is_prime.set();
    std::vector<int> prime;
    for (int i = 2; i < kLimit; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
        }
        for (int j = 0; i * prime[j] < kLimit; j++) {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
    return prime;
}

void Solve(int n) {
    static std::vector<int> prime = Sieve();
    for (const int a : prime) {
        int b = n - a;
        auto it = std::lower_bound(prime.begin(), prime.end(), b);
        if (it != prime.end() && *(it) == b) {
            std::cout << n << " = " << a << " + " << b << '\n';
            return;
        }
    }
    std::cout << "Goldbach\'s conjecture is wrong.\n";
}

int main() {
    int n;
    while (std::cin >> n && n) {
        Solve(n);
    }
}
