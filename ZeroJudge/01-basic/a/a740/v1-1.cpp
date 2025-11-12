#include <iostream>

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
    for (int i = 5; i * i <= num; i += 6) {
        PrimeFactorSumHelper(num, result, i);
        PrimeFactorSumHelper(num, result, i + 2);
    }
    if (num > 1) {
        result += num;
    }
    return result;
};

int main() {
    int num;
    while (std::cin >> num) {
        std::cout << PrimeFactorSum(num) << '\n';
    }
}
