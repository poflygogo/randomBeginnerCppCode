#include <cstdlib>  // std::abs
#include <iomanip>  // std::setprecision, std::fixed
#include <iostream>

int main() {
    double hour, minute;
    char c;  // separator
    while (std::cin >> hour >> c >> minute && !(hour == 0 && minute == 0)) {
        double degree = std::abs(minute * 6 - hour * 30 - minute / 2);
        std::cout << std::setprecision(3) << std::fixed << (degree < 180 ? degree : 360 - degree) << '\n';
    }
}
