#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    const int kPlace = 2;
    double a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

    double denominator = a1 * b2 - a2 * b1;
    double dx = c1 * b2 + c2 * b1;
    double dy = c1 * a2 + c2 * a1;

    if (denominator) {
        cout << "x=" << fixed << setprecision(kPlace) << (c1 * b2 - c2 * b1) / denominator << endl;
        cout << "y=" << fixed << setprecision(kPlace) << (a1 * c2 - a2 * c1) / denominator << endl;
    } else if (dx == dy && dy == 0) {
        cout << "Too many" << endl;
    } else {
        cout << "No answer" << endl;
    }
}

// 用克拉馬公式(Cramer's formula)處理
