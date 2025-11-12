#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        int a, b, s, e;
        cin >> a >> b;
        s = a + (a % 2 == 0);
        e = b - (b % 2 == 0);
        cout << "Case " << test_case << ": " << pow((e + 1) / 2, 2) - pow((s - 1) / 2, 2) << "\n";
    }
}
