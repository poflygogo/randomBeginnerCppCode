#include <iomanip>
#include <iostream>
using namespace std;

string PrimeSum(int n) {
    if (n == 1) {
        return "DEFICIENT";
    }
    int sum = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (n != n / i) {
                sum += n / i;
            }
        }
    }
    if (sum == n) {
        return "PERFECT";
    } else if (sum < n) {
        return "DEFICIENT";
    } else {
        return "ABUNDANT";
    }
}

int main() {
    cout << "PERFECTION OUTPUT\n";
    int n;
    while (cin >> n && n) {
        cout << setw(5) << n << setw(0) << "  " << PrimeSum(n) << '\n';
    }
    cout << "END OF OUTPUT";
}
