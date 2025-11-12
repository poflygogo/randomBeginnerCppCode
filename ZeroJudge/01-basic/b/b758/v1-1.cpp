#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    y += 30;
    x += 2;
    if (y >= 60) {
        y %= 60;
        x += 1;
    }
    if (x >= 24) {
        x %= 24;
    }
    cout << setw(2) << setfill('0') << x
         << ':'
         << setw(2) << setfill('0') << y;
}
