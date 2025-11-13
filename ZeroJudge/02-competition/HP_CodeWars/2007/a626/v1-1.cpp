#include <algorithm>  // distance, upper_bound
#include <iomanip>    // setw, right
#include <iostream>
#include <vector>

std::vector<int> Sieve(const int limit = 1000) {
    std::vector<char> is_prime(limit + 1, true);
    std::vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

int main() {
    constexpr int width = 10;
    std::vector<int> primes = Sieve();
    int n;
    while (std::cin >> n) {
        size_t rgt =
            std::distance(primes.begin(), std::upper_bound(primes.begin(), primes.end(), n));
        int cnt = 0;
        for (size_t i = 0; i < rgt; i++) {
            std::cout << std::setw(width) << std::right << primes[i]
                      << ((i + 1 >= primes.size() || ++cnt == 5) ? "\n" : "");
            cnt %= 5;
        }
        std::cout << '\n';
    }
}
