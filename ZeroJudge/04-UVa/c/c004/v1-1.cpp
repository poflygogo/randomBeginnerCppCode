#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int add, sub;
        cin >> add >> sub;
        int num1 = add + sub;
        int num2 = add - num1 / 2;
        if (num1 % 2 == 0 && num2 >= 0) {
            cout << num1 / 2 << ' ' << num2 << '\n';
        } else {
            cout << "impossible" << '\n';
        }
    }
}
