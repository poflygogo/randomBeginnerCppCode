#include <iostream>
using namespace std;

int main() {
    int a, b;
    short c;
    while (cin >> a >> b >> c) {
        cout << a / b << '.';
        a %= b;
        while (c--) {
            a *= 10;
            cout << a / b;
            a %= b;
        }
        cout << endl;
    }
}