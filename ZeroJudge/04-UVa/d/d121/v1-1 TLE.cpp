#include <iostream>
#include <string>

void print_factor(std::string& res, int& n, const int p) {
    while (n % p == 0) {
        res += std::to_string(p) + " x ";
        n /= p;
    }
}

int main() {
    int n;
    while (std::cin >> n && n) {
        std::string res = std::to_string(n) + " = ";
        if (n < 0) {
            res += "-1 x ";
            n = -n;
        }
        print_factor(res, n, 2);
        print_factor(res, n, 3);
        for (int i = 5; i < n; i += 6) {
            print_factor(res, n, i);
            print_factor(res, n, i + 2);
        }
        if (n > 1) {
            res += std::to_string(n);
        }
        while (res.back() == ' ' || res.back() == 'x') res.pop_back();
        std::cout << res << '\n';
    }
}