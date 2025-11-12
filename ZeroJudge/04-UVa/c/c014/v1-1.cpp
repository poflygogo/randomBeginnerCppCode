#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    string a, b;
    while (cin >> a >> b && !(a == "0" && b == "0")) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if (a.size() < b.size()) {
            swap(a, b);
        }
        a += '0';

        int cnt = 0;
        int carry = 0;
        for (int i = 0; i < a.size(); i++) {
            int sum = (a[i] - '0') + (i < b.size() ? b[i] - '0' : 0) + carry;
            a[i] = sum % 10 + '0';
            carry = sum / 10;
            cnt += carry;
        }
        if (cnt) {
            cout << cnt << " carry operation" << (cnt > 1 ? "s.\n" : ".\n");
        } else {
            cout << "No carry operation." << '\n';
        }
    }
}
