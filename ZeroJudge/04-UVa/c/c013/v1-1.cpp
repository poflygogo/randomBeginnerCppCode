#include <iostream>
using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        string s;
        for (int i = 1; i < a; i++) {
            s += string(i, '0' + i) + '\n';
        }
        for (int i = a; i > 0; i--) {
            s += string(i, '0' + i) + '\n';
        }
        s += '\n';
        for (int i = 0; i < b; i++) {
            cout << s;
        }
    }
}
