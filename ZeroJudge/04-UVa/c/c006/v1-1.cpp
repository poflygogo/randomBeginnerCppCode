#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    while (cin >> a >> b >> c >> d && (a || b || c || d)) {
        cout << 1080 + 9 * (    // # 360 * (2 + 1)
            (40 + a - b) % 40 + // 順時鐘轉直到到達第 1 個號碼
            (40 + c - b) % 40 + // 逆時鐘轉直到到達第 2 個號碼
            (40 + c - d) % 40   // 順時鐘轉直到到達第 3 個號碼
        ) << '\n';
    }
}
