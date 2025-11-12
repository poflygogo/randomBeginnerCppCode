#include <iostream>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        int sum = a;
        int cnt = 1;
        int i = a + 1;
        while (sum <= b) {
            sum += i++;
            cnt++;
        }
        cout << cnt << endl;
    }
}