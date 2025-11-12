#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        short a;
        long b, c;
        cin >> a >> b >> c;
        switch (a) {
        case 1:
            b += c;
            break;
        case 2:
            b -= c;
            break;
        case 3:
            b *= c;
            break;
        case 4:
            b /= c;
            break;
        default: // should not happen
            break;
        }
        cout << b << endl;
    }
}