#include <array>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    const int kTotalFingers = 10;
    const map<int, array<bool, kTotalFingers>> kSaxophone = {
        {'c', {0, 1, 1, 1, 0, 0, 1, 1, 1, 1}},
        {'d', {0, 1, 1, 1, 0, 0, 1, 1, 1, 0}},
        {'e', {0, 1, 1, 1, 0, 0, 1, 1, 0, 0}},
        {'f', {0, 1, 1, 1, 0, 0, 1, 0, 0, 0}},
        {'g', {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}},
        {'a', {0, 1, 1, 0, 0, 0, 0, 0, 0, 0}},
        {'b', {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}},
        {'C', {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}},
        {'D', {1, 1, 1, 1, 0, 0, 1, 1, 1, 0}},
        {'E', {1, 1, 1, 1, 0, 0, 1, 1, 0, 0}},
        {'F', {1, 1, 1, 1, 0, 0, 1, 0, 0, 0}},
        {'G', {1, 1, 1, 1, 0, 0, 0, 0, 0, 0}},
        {'A', {1, 1, 1, 0, 0, 0, 0, 0, 0, 0}},
        {'B', {1, 1, 0, 0, 0, 0, 0, 0, 0, 0}},
    };
    array<bool, kTotalFingers> fingers_status = {false};
    array<int, kTotalFingers> fingers_press = {0};
    int t;
    string s;
    cin >> t;
    cin.ignore();
    while (t--) {
        // 就算是空行也要處理
        // 空行代表沒有音符的樂譜
        // 是一個空字串
        getline(cin, s);
        
        for (const char &c : s) {
            for (int i = 0; i < kTotalFingers; ++i) {
                if (fingers_status[i] == 1 && kSaxophone.at(c)[i] == 0) {
                    fingers_status[i] = 0;
                } else if (fingers_status[i] == 0 && kSaxophone.at(c)[i] == 1) {
                    fingers_status[i] = 1;
                    fingers_press[i] += 1;
                }
            }
        }
        for (const int &cnt : fingers_press) {
            cout << cnt << ' ';
        }
        cout << '\n';
        fingers_status.fill(false);
        fingers_press.fill(0);
    }
}
