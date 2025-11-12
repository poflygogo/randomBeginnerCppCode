#include <iostream>
#include <utility>
using namespace std;

int Gcd(int a, int b) {
    while (b) {
        swap(a, b);
        b %= a;
    }
    return a;
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        cout << Gcd(a, b) << '\n';
    }
}
