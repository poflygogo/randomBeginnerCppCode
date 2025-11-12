#include <iostream>
using namespace std;

int Gcd(int a, int b) { return b == 0 ? a : Gcd(b, a % b); }

int main() {
    int a, b;
    while (cin >> a >> b) {
        cout << Gcd(a, b) << '\n';
    }
}