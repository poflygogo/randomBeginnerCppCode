#include <iostream>
using namespace std;

int main() {
    long long int n;
    while (cin >> n && n >= 0) {
        cout << (n + 1) * n / 2 + 1 << '\n';
    }
}
