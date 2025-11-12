#include <iostream>
using namespace std;

long long int f(long long int n) { return n == 1 ? 1 : n + f(n - 1); }
long long int g(long long int n) { return n == 1 ? 1 : f(n) + g(n - 1); }

int main() {
    long long int n;
    while (cin >> n) {
        cout << f(n) << " " << g(n) << endl;
    }
}