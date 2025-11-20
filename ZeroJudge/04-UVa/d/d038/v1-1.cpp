#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<long long> fib = {1, 2};  // fib(1), fib(2) <- fibornacci sequence
    long long n;
    while (cin >> n && n) {
        while (fib.size() < n) {
            fib.push_back(fib.back() + fib[fib.size() - 2]);  // fib(n) = fib(n - 1) + fib(n - 2)
        }
        cout << fib[n - 1] << '\n';
    }
    return 0;
}
