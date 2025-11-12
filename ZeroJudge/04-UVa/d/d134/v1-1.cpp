#include <iostream>
#include <sstream>

class Fraction {
   private:
    unsigned long long n;  // numerator
    unsigned long long d;  // dominator

    unsigned long long gcd(unsigned long long a, unsigned long long b) {
        return !b ? a : gcd(b, a % b);
    }
    void simplify() {
        unsigned long long g = gcd(this->n, this->d);
        this->n /= g;
        this->d /= g;
    }

   public:
    Fraction(unsigned long long a) : n(a), d(1) {};
    Fraction(unsigned long long a, unsigned long long b) : n(a), d(b) { simplify(); };
    Fraction& operator*=(const Fraction& rhs) {
        unsigned long long g1 = gcd(this->n, rhs.d);
        unsigned long long g2 = gcd(this->d, rhs.n);
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
    unsigned long long a, b;
    while (std::cin >> a >> b && !(a == 0 && b == 0)) {
        std::cout << a << " things taken " << b << " at a time is ";
        if (b > a / 2) {
            b = a - b;
        }
        Fraction res(1);
        unsigned long long i = a - b + 1;
        unsigned long long j = 1;
        while (i <= a || j <= b) {
            res *= Fraction((i <= a ? i : 0), (j <= b ? j : 1));
            i++;
            j++;
        }
        std::cout << res << " exactly.\n";
    }
}
