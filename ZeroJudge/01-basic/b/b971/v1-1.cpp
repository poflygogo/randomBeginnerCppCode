#include <iostream>
using namespace std;

int main() {
    int a1, an, d;
    cin >> a1 >> an >> d;
    an += d;
    for (int i = a1; i != an; i += d) {
        cout << i << ' ';
    }
}
