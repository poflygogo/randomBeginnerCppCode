#include <array>
#include <iomanip>
#include <iostream>

std::string BanglaNumber(long long num) {
    static const std::array<std::pair<std::string, long long>, 4> kBanglaUnit = {
        {{"kuti", 10000000}, {"lakh", 100000}, {"hajar", 1000}, {"shata", 100}}};

    for (auto&& unit : kBanglaUnit) {
        if (num >= unit.second) {
            int a = num / unit.second;
            int b = num % unit.second;
            if (b == 0) {
                return BanglaNumber(a) + ' ' + unit.first;
            } else {
                return BanglaNumber(a) + ' ' + unit.first + ' ' + BanglaNumber(b);
            }
        }
    }
    return std::to_string(num);
}

int main() {
    int cnt = 1;
    long long num;
    while (std::cin >> num) {
        std::cout << std::right << std::setw(4) << cnt++ << ". " << BanglaNumber(num) << '\n';
    }
}
