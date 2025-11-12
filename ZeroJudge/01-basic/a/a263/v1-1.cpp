#include <iostream>
using namespace std;

// 判斷是否是閏年
bool IsLeap(int year) {
    return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}

// 計算傳入的日期與西元 1 年 1 月 1 日相差幾天
int ToDays(int y, int m, int d) {
    const int kLeapYear = 366;
    const int kCommonYear = 365;
    const int kMonthDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int result = d;

    for (int i = 0; i < m - 1; i++) {
        result += kMonthDay[i];
    }
    if (m > 2 && IsLeap(y)) {   // 如果該年是閏年，要加 1
        result++;
    }

    y -= 1;
    int cnt_leap = y / 4 - y / 100 + y / 400;
    int cnt_common = y - cnt_leap;
    result += kLeapYear * cnt_leap;
    result += kCommonYear * cnt_common;

    return result;
}

int main() {
    int y1, m1, d1;
    int y2, m2, d2;
    while (cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2) {
        cout << abs(ToDays(y1, m1, d1) - ToDays(y2, m2, d2)) << endl;
    }
}
