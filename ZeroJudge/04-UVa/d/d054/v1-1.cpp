#include <algorithm>
#include <iostream>
#include <string>

std::string BigIntAdd(std::string num1, std::string num2) {
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());
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
        std::string num1(length, '0'), num2(length, '0');
        for (size_t i = 0; i < length; ++i) {
            std::cin >> num1[i] >> num2[i];
        }
        std::cout << BigIntAdd(num1, num2) << "\n\n";
    }
}
