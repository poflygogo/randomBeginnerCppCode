// UVa 11586 - Train Tracks
// ZeroJudge d275
// C++14

#include <iostream>
#include <limits>
#include <string>

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    while (t--) {
        std::string s;
        std::getline(std::cin, s);

        int cnt_M = 0;
        int cnt_F = 0;
        for (const char c : s) {
            switch (c) {
            case 'M':
                cnt_M++;
                break;
            case 'F':
                cnt_F++;
                break;
            }
        }

        std::cout << (cnt_F == cnt_M && (cnt_F + cnt_M > 2) ? "LOOP" : "NO LOOP") << '\n';
    }
}

// 軌道是可以翻轉的，所以
// "MF FM" 這種的應視為 LOOP
// 故只需要檢查 F 和 M 的總數是否相同即可
// 記得要判斷當軌道總數只有 1 的情況
