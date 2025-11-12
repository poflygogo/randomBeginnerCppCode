#include <iostream>
using namespace std;

int main() {
    int a, b;
    short c;
    while (cin >> a >> b >> c) {
        cout << a / b << '.';
        a %= b;
        int decimal[c];
        for (int i = 0; i < c; i++) {
            a *= 10;
            decimal[i] = a / b;
            a %= b;
        }
        for (short digit : decimal) {
            cout << digit;
        }
        cout << endl;
    }
}