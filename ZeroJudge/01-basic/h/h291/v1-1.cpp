#include <array>
#include <iostream>

const std::array<std::string, 12> month = {
    "January", "February", "March",     "April",   "May",      "June",
    "July",    "August",   "September", "October", "November", "December"};

int main() {
    int n;
    std::cin >> n;
    std::cout << month[n - 1];
}
