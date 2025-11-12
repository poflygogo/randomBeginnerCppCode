#include <iostream>
using namespace std;

// 會溢位

int f(int n) { return n == 1 ? 1 : n + f(n - 1); }
int g(int n) { return n == 1 ? 1 : f(n) + g(n - 1); }

int main() {
    int n;
    while (cin >> n) {
        cout << f(n) << " " << g(n) << endl;
    }
}