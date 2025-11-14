#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

// 特判 -0.000 應輸出 0.000，如果沒有這需求就不用寫這函數了
string to_str(double x) {
    stringstream ss;
    ss << fixed << setprecision(3) << x;
    string s = ss.str();
    if (s == "-0.000") s = "0.000";
    return s;
}

int main() {
    // {x, y}{第 n 根手指}{開始 or 結束}
    double x11, y11, x12, y12, x21, y21, x22, y22;
    while (cin >> x11 >> y11 >> x12 >> y12 >> x21 >> y21 >> x22 >> y22 &&
           (x11 || y11 || x12 || y12 || x21 || y21 || x22 || y22)) {
        // 開始中心
        double cx1 = (x11 + x21) / 2.0;
        double cy1 = (y11 + y21) / 2.0;
        // 結束中心
        double cx2 = (x12 + x22) / 2.0;
        double cy2 = (y12 + y22) / 2.0;

        // 平移，往原點取整數
        int dx = ((cx2 - cx1 < 0) ? ceil(cx2 - cx1) : floor(cx2 - cx1));
        int dy = ((cy2 - cy1 < 0) ? ceil(cy2 - cy1) : floor(cy2 - cy1));

        // 開始距離
        double dx1 = x21 - x11;
        double dy1 = y21 - y11;
        double dist1 = sqrt(dx1 * dx1 + dy1 * dy1);
        // 結束距離
        double dx2 = x22 - x12;
        double dy2 = y22 - y12;
        double dist2 = sqrt(dx2 * dx2 + dy2 * dy2);

        double scale = dist2 / dist1;

        // 斜率
        double m1 = dy1 / dx1;
        double m2 = dy2 / dx2;
        double angle = atan((m2 - m1) / (1 + m1 * m2));

        cout << dx << " " << dy << " " << to_str(scale) << " " << to_str(angle) << "\n";
    }
}
