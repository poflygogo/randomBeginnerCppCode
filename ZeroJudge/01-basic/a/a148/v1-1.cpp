#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int sum = 0;
        int tmp;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            sum += tmp;
        }
        if (sum <= 59 * n) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}