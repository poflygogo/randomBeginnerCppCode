#include <array>
#include <iostream>

int main() {
    std::array<int, 4> ipv4;
    long long n;
    while (std::cin >> n) {
        ipv4[0] = n >> 24;
        ipv4[1] = (n >> 16) & 0xFF;
        ipv4[2] = (n >> 8) & 0xFF;
        ipv4[3] = n & 0xFF;
        std::cout << ipv4[0] << '.' << ipv4[1] << '.' << ipv4[2] << '.' << ipv4[3] << '\n';
    }
}
