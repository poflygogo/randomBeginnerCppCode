#include <iostream>
#include <limits>  // for std::numeric_limits
#include <map>
#include <string>
#include <vector>

std::vector<int> eratosthenes() {
    // this will cause MLE(memory limit exceeded)
    // because it will eat 2^32 bytes of memory(aka 2GB)
    int limit = std::numeric_limits<int>::max();

    // btw use long long instead
    std::vector<int> primes;
    std::vector<char> is_prime(limit, true);

    for (int i = 2; i < limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j < limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

std::map<int, int> factorize(int n) {
    static std::vector<int> primes = eratosthenes();
    std::map<int, int> counter;
    if (n < 0) {
        counter[-1]++;
        n = -n;
    }
    for (size_t i = 0; i < primes.size() && primes[i] <= n; ++i) {
        while (n % primes[i] == 0) {
            counter[primes[i]]++;
            n /= primes[i];
        }
    }
    if (n > 1) {  // is it necessary?
        counter[n]++;
    }
    return counter;
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::map<int, int> counter = factorize(n);
        std::cout << n << " = ";
        for (auto it = counter.begin(); it != counter.end(); ++it) {
            std::string res;
            std::string s = std::to_string(it->first) + " x ";
            for (int i = 0; i < it->second; ++i) {
                res += s;
            }
            if (std::next(it) == counter.end()) {
                while (res.back() == ' ' || res.back() == 'x') {
                    res.pop_back();
                }
            }
            std::cout << res;
        }
        std::cout << "\n";
    }
}