#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int product = 1;
        do {
            int tmp = n % 10;
            product *= tmp;
        } while (n /= 10);
        cout << product << endl;
    }
}