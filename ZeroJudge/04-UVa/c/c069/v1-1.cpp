#include <array>
#include <iostream>
#include <numeric>

const std::array<std::string, 12> month_name = {"January",   "February", "March",    "April",
                                                "May",       "June",     "July",     "August",
                                                "September", "October",  "November", "December"};
const std::array<std::string, 7> day_name = {"Monday", "Tuesday",  "Wednesday", "Thursday",
                                             "Friday", "Saturday", "Sunday"};
const std::array<int, 13> month_day = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool IsLeap(int y) {
    if (y > 1752) {
        return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
    } else {
        return y % 4 == 0;
    }
}

bool IsvalidDay(int m, int d, int y) {
    if (m < 1 || m > 12) {
        return false;
    }
    if (d < 1 || d > (month_day[m] + (m == 2 && IsLeap(y)))) {
        return false;
    }
    if (y == 1752 && m == 9 && d > 2 && d < 14) {
        return false;
    }
    return true;
}

int CountDays(int m, int d, int y) {
    int res = 4;
    res += (y - 1) * 365;
    for (int i = 4; i < y; i += 4) {
        res += IsLeap(i);
    }
    res += std::accumulate(month_day.begin(), month_day.begin() + m, 0);
    res += (m > 2 && IsLeap(y));
    res += d;
    if ((y > 1752) || (y == 1752 && (m > 9 || (m == 9 && d >= 14)))) {
        res += 10;
    }
    return res;
}

int main() {
    int m, d, y;
    while (std::cin >> m >> d >> y && m || d || y) {
        if (IsvalidDay(m, d, y)) {
            int days = CountDays(m, d, y);
            std::cout << month_name[m - 1] << ' ' << d << ", " << y << " is a "
                      << day_name[days % 7] << '\n';
        } else {
            std::cout << m << '/' << d << '/' << y << " is an invalid date.\n";
        }
    }
}
