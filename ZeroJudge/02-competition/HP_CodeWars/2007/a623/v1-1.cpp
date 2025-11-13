#include <iostream>
#include <sstream>

class Fraction {
   private:
    long long n;  // numerator
    long long d;  // dominator

    long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
    void simplify() {
        long long g = gcd(this->n, this->d);
        this->n /= g;
        this->d /= g;
    }

   public:
    Fraction(long long a) : n(a), d(1) {};
    Fraction(long long a, long long b) : n(a), d(b) { simplify(); };
    Fraction& operator*=(const Fraction& rhs) {
        long long g1 = gcd(this->n, rhs.d);
        long long g2 = gcd(this->d, rhs.n);
        this->n /= g1;
        this->d /= g2;
        this->n *= rhs.n / g2;
        this->d *= rhs.d / g1;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& item);
};

std::ostream& operator<<(std::ostream& os, const Fraction& item) {
    os << item.n;
    return os;
}

int main() {
    long long a, b;
    while (std::cin >> a >> b && !(a == 0 && b == 0)) {
        if (b > a / 2) {
            b = a - b;
        }
        Fraction res(1);
        long long i = a - b + 1;
        long long j = 1;
        while (i <= a || j <= b) {
            res *= Fraction((i <= a ? i : 0), (j <= b ? j : 1));
            i++;
            j++;
        }
        std::cout << res << '\n';
    }
}
