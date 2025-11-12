#include <algorithm>
#include <array>
#include <iostream>

struct DateInfo {
    std::string month_str;
    std::string date_str;
    int date;
    int month;
    int year;

    void str_to_int();
    int leap_cnt();
    bool is_leap();
};

void DateInfo::str_to_int() {
    static const std::array<std::string, 12> mon = {
        "January", "February", "March",     "April",   "May",      "June",
        "July",    "August",   "September", "October", "November", "December"};
    month = std::distance(mon.begin(), std::find(mon.begin(), mon.end(), month_str)) + 1;
    date_str.pop_back();
    date = std::stoi(date_str);
}

int DateInfo::leap_cnt() { return year / 4 - year / 100 + year / 400; }

bool DateInfo::is_leap() { return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0); }

int main() {
    int n;
    std::cin >> n;
    DateInfo a, b;
    for (int test_case = 1; test_case <= n; test_case++) {
        std::cin >> a.month_str >> a.date_str >> a.year;
        std::cin >> b.month_str >> b.date_str >> b.year;
        a.str_to_int();
        b.str_to_int();

        int res = b.leap_cnt() - a.leap_cnt() + a.is_leap();
        if (a.is_leap() && a.month > 2) {
            res -= 1;
        }
        if (b.is_leap() && (b.month < 2 || (b.month == 2 && b.date < 29))) {
            res -= 1;
        }
        std::cout << "Case " << test_case << ": " << std::max(res, 0) << '\n';
    }
}
