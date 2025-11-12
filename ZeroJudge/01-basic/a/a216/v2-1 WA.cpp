#include <iostream>
using namespace std;

// 會溢位

int f(long long int n) { return n * (n + 1) / 2; }
int g(long long int n) { return n * (n + 1) * (2 * n + 4) / 12; }

int main() {
    long long int n;
    while (cin >> n) {
        cout << f(n) << " " << g(n) << endl;
    }
}