#include <iostream>

int main() {
    long long n, m;
    std::cin >> n >> m;
    long long val = n;
    do {
        std::cout << val << '\n';
        val *= n;
    } while (val <= m);
}
