#include <iostream>

void count_prime_factors_helper(int& cnt, int& n, const int p) {
    if (n % p == 0) cnt++;
    while (n % p == 0) n /= p;
}

int count_prime_factors(int n) {
    int cnt = 0;
    count_prime_factors_helper(cnt, n, 2);
    count_prime_factors_helper(cnt, n, 3);
    for (int p = 5; p * p <= n; p += 6) {
        count_prime_factors_helper(cnt, n, p);
        count_prime_factors_helper(cnt, n, p + 2);
    }
    return cnt + (n > 1);
}

int main() {
    int n;
    while (std::cin >> n && n) {
        std::cout << n << " : " << count_prime_factors(n) << "\n";
    }
}
