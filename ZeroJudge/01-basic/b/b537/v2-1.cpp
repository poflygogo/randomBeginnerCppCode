#include <iostream>
using namespace std;

int Gcd(int a, int b) { return b == 0 ? a : Gcd(b, a % b); }

void DivGCD(int &a, int &b) {
    int g = Gcd(a, b);
    a /= g;
    b /= g;
}

long long Solution(int a, int b) {
    if (a == b) {
        return 1;
    } else if (a > b) {
        return Solution(a - b, b) * 2;
    } else {
        return Solution(b, a) + 1;
    }
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        DivGCD(a, b);
        cout << Solution(a, b) << '\n';
    }
}
