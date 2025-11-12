#include <iostream>
using namespace std;

int main() {
    long long int n;
    while (cin >> n) {
        long long int f = 1;
        long long int g = 1;
        for (int i = 2; i <= n; i++) {
            f += i;
            g += f;
        }
        cout << f << " " << g << endl;
    }
}