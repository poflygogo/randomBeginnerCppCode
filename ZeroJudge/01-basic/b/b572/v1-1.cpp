#include <iostream>
using namespace std;

int main() {
    // 循環 t 次
    // 目前時間為 h1:m1
    // 發車時間為 h2:m2
    // 移動去車站的時間為 m3
    int t, h1, m1, h2, m2, m3;
    cin >> t;
    while (t--) {
        cin >> h1 >> m1 >> h2 >> m2 >> m3;
        if ((h2 * 60 + m2) - (h1 * 60 + m1) >= m3) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
