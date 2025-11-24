#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>

void factorize_helper(int& n, const int p, std::unordered_map<int, int>& counter, std::vector<int>& factors) {
    if (n % p == 0) {
        factors.push_back(p);
    }
    while (n % p == 0) {
        counter[p]++;
        n /= p;
    }
}

std::tuple<std::unordered_map<int, int>, std::vector<int>> factorize(int n) {
    std::unordered_map<int, int> counter;
    std::vector<int> factors;
    if (n < 0) {
        counter[-1]++;
        factors.push_back(-1);
        n *= -1;
    }
    factorize_helper(n, 2, counter, factors);
    factorize_helper(n, 3, counter, factors);
    for (int p = 5; p * p <= n; p += 6) {
        factorize_helper(n, p, counter, factors);
        factorize_helper(n, p + 2, counter, factors);
    }
    if (n > 1) {
        counter[n]++;
        factors.push_back(n);
    }
    return std::make_tuple(counter, factors);
}

int main() {
    // boost IO
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // -------------------------------

    int n;
    while (std::cin >> n && n) {
        std::unordered_map<int, int> counter;
        std::vector<int> factors;
        std::tie(counter, factors) = factorize(n);
        std::cout << n << " = ";
        bool is_first = true;
        for (auto&& i : factors) {
            if (!is_first) std::cout << " x ";
            std::cout << i;
            is_first = false;
        }
        std::cout << "\n";
    }
}
