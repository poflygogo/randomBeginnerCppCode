#include <array>
#include <iostream>
using namespace std;

int main()
{
    // HS = HeavenlyStems
    // EB = EarthlyBranch
    const int kPeriodHS = 10;
    const int kPeriodEB = 12;
    const array<string, kPeriodHS> kHS = {"甲", "乙", "丙", "丁", "戊",
                                          "己", "庚", "辛", "壬", "癸"};
    const array<string, kPeriodEB> kEB = {"子", "丑", "寅", "卯", "辰", "巳",
                                          "午", "未", "申", "酉", "戌", "亥"};
    int year;
    while (cin >> year)
    {
        cout << kHS[(year + 6) % kPeriodHS] + kEB[(year + 8) % kPeriodEB] << '\n';
    }
}
