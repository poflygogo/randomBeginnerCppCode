#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        cout << "f91(" << n << ") = " << (n <= 101 ? 91 : n - 10) << '\n';
    }
}
