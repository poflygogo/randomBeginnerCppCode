#include <cstddef>   // size_t
#include <iomanip>   // setw
#include <iostream>  // cin, cout
#include <string>    // string
#include <vector>    // vector

using namespace std;

vector<int> eratosthenes(const int limit) {
    vector<int> primes;
    vector<bool> isPrime(limit + 1, true);
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return primes;
}

vector<vector<int>> precompute(const int limit) {
    const vector<int> primes = eratosthenes(limit);
    vector<vector<int>> factorization(limit + 1, vector<int>(primes.size() + 1, 0));
    for (int num = 2; num <= limit; num++) {
        int tmp = num;
        for (size_t p = 0; p < primes.size() && primes[p] <= tmp; p++) {
            while (tmp % primes[p] == 0) {
                tmp /= primes[p];
                factorization[num][p]++;
            }
        }
    }
    return factorization;
}

int main() {
    constexpr int kMaxN = 100;
    vector<vector<int>> factorization = precompute(kMaxN);

    // prefix sum
    for (size_t i = 2; i < factorization.size(); ++i) {
        for (size_t j = 0; j < factorization[i].size(); ++j) {
            factorization[i][j] += factorization[i - 1][j];
        }
    }

    int n;
    while (cin >> n && n != 0) {
        cout << setw(3) << n << "! =";

        vector<int>& factor = factorization[n];
        for (size_t i = 0; i < factor.size() && factor[i] > 0; ++i) {
            if (i == 15) {
                cout << '\n' << string(6, ' ');
            }
            cout << setw(3) << factor[i];
        }
        cout << '\n';
    }
}
