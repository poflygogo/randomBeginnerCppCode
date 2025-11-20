#include <iostream>

using namespace std;

int solve(int n) {
    if (n < 10) {
        return n;
    }
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return solve(sum);
}

int main() {
    int n;
    while (cin >> n && n) {
        cout << solve(n) << '\n';
    }
}
