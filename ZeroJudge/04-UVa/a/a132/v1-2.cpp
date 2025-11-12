#include <bitset>
#include <iostream>

int main() {
    int n;
    while (std::cin >> n && n) {
        std::bitset<32> bit(n);
        int msb = 32;  // bits 最高有效位
        while (bit[msb] != 1) {
            msb--;
        }
        std::cout << "The parity of " << bit.to_string().substr(31 - msb) << " is " << bit.count()
                  << " (mod 2).\n";
    }
}
