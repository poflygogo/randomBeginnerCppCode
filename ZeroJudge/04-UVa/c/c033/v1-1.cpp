#include <algorithm>  // distance, upper_bound, copy
#include <bitset>
#include <iostream>
#include <iterator>  // std::ostream_iterator
#include <sstream>   // std::ostream_iterator
#include <vector>
using namespace std;

vector<int> Sieve() {
    constexpr int limit = 1000;
    bitset<limit> is_prime;
    is_prime.set();
    vector<int> prime;
    prime.reserve(limit);
    prime.push_back(1);  // why? why 1 is prime? why? baby why?
    for (int i = 2; i < limit; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
        }
        for (int j = 1; i * prime[j] < limit; j++) {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
    return prime;
}

int main() {
    vector<int> prime = Sieve();

    int a, b;
    while (cin >> a >> b) {
        cout << a << ' ' << b << ": ";
        int k = distance(prime.begin(), upper_bound(prime.begin(), prime.end(), a));

        if (b >= k) {
            copy(prime.begin(), prime.begin() + k, ostream_iterator<int>(cout, " "));
        } else if (k % 2 == 0) {
            copy(prime.begin() + (k / 2 - b), prime.begin() + (k / 2 + b), ostream_iterator<int>(cout, " "));
        } else {
            copy(prime.begin() + (k / 2 - b + 1), prime.begin() + (k / 2 + b), ostream_iterator<int>(cout, " "));
        }
        cout << '\n';
    }
}
