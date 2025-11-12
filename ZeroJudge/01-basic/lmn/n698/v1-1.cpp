#include <iostream>

int main() {
    double num;
    std::cin >> num;
    if (num >= 17.43) {
        std::cout << 0;
    } else if (num >= 17.00) {
        std::cout << 1;
    } else if (num >= 16.50) {
        std::cout << 3;
    } else if (num >= 16.00) {
        std::cout << 7;
    } else if (num >= 15.50) {
        std::cout << 10;
    } else if (num >= 15.00) {
        std::cout << 15;
    } else {
        std::cout << 20;
    }
}
