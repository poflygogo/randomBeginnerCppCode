#include <iostream>
#include <iterator>  // std::next
#include <map>
#include <string>

void factorize_helper(int& n, const int p, std::map<int, int>& counter) {
    while (n % p == 0) {
        counter[p]++;
        n /= p;
    }
}

void factorize(int n, std::map<int, int>& counter) {
    factorize_helper(n, 2, counter);
    factorize_helper(n, 3, counter);
    for (int p = 5; p * p <= n; p += 6) {
        factorize_helper(n, p, counter);
        factorize_helper(n, p + 2, counter);
    }
    if (n > 1) {
        counter[n]++;
    }
}

int main() {
    // boost IO
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // -------------------------------

    int n;
    std::map<int, int> counter;
    while (std::cin >> n && n) {
        std::cout << n << " = ";
        counter.clear();
        if (n < 0) {
            counter[-1]++;
            n = -n;
        }
        factorize(n, counter);
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