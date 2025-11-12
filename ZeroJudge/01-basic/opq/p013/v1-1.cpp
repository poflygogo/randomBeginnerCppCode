#include <iostream>

int fib(int n) {
    std::cout << "f(" << n << ')' << (n < 2 ? '\n' : ' ');
    if (n < 2) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int n;
    std::cin >> n;
    int res = fib(n);
    std::cout << "f(" << n << ") = " << res;
}
