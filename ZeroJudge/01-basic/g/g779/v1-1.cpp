#include <iostream>

int main() {
    std::string a, b;
    std::cin >> a >> b;
    if (a.find(b) != std::string::npos || std::stoi(a) % std::stoi(b) == 0) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}
