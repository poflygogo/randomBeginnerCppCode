#include <iostream>

int main() {
    std::string s;
    std::cin >> s;
    int sum = 0;
    for (char c : s) {
        sum += c - 'A' + 1;
    }
    std::cout << sum;
}
