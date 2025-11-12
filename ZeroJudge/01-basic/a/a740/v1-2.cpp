#include <iostream>
using namespace std;

void PrimeFactorSumHelper(int &num, int &result, const int &p) {
    while (num % p == 0) {
        num /= p;
        result += p;
    }
}

int PrimeFactorSum(int num) {
    int result = 0;
    PrimeFactorSumHelper(num, result, 2);
    PrimeFactorSumHelper(num, result, 3);
    for (int i = 5; i * i <= num; i += (i % 6 == 5 ? 2 : 4)) {
        PrimeFactorSumHelper(num, result, i);
    }
    if (num > 1) {
        result += num;
    }
    return result;
};

int main() {
    int num;
    while (cin >> num) {
        cout << PrimeFactorSum(num) << '\n';
    }
}
