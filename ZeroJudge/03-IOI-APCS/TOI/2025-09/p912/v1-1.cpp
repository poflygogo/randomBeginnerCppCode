#include <iostream>

int main() {
    int p, d, t, c;
    std::cin >> p >> d >> t >> c;
    if ((d >= 30 && c == 0) || (d <= 15 && c == 1)) {
        p -= 5;
    }
    if ((7 <= t && t < 10) || (14 <= t && t < 16)) {
        p -= 5;
    }
    std::cout << p;
}
