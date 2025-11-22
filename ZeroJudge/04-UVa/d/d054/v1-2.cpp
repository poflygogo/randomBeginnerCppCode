#include <algorithm>
#include <iostream>
#include <string>

std::string BigIntAdd(std::string num1, std::string num2) {
    int carry = 0;
    for (size_t i = 0; i < num1.length(); ++i) {
        int sum = num1[i] - '0' + num2[i] - '0' + carry;
        num1[i] = sum % 10 + '0';
        carry = sum / 10;
    }
    std::reverse(num1.begin(), num1.end());
    return num1;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int length;
        std::cin >> length;
        std::string reverse_num1(length, '0'), reverse_num2(length, '0');
        for (int i = length - 1; i >= 0; --i) {
            std::cin >> reverse_num1[i] >> reverse_num2[i];
        }
        std::cout << BigIntAdd(reverse_num1, reverse_num2) << "\n\n";
    }
}
