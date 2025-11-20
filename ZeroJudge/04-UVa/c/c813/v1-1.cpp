#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        n %= 9;
        cout << (n ? n : 9) << '\n';
    }
}
