#include <array>
#include <iostream>

int main() {
    std::array<int, 4> ipv4;
    long long n;
    while (std::cin >> n) {
        for (size_t i = 0; i < ipv4.size(); ++i) {
            ipv4[i] = n % 256;
            n /= 256;
        }
        std::cout << ipv4[3] << '.' << ipv4[2] << '.' << ipv4[1] << '.' << ipv4[0] << '\n';
    }
}
