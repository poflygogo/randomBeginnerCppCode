#include <iostream>
using namespace std;

int main() {
    int candy, weedle;
    cin >> candy >> weedle;
    candy += weedle;
    if (candy < 13) {
        cout << 0;
    } else {
        int t = (candy - 13) / 11 + 1;
        cout << (t >= weedle ? weedle : t);
    }
}
