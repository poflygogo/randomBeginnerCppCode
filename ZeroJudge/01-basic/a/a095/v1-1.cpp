#include <iostream>
using namespace std;

int main() {
    int n, m, res;
    while (cin >> n >> m) {
        res = n == m ? m : m + 1;
        cout << res << endl;
    }
}