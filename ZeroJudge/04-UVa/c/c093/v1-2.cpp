#include <algorithm>  // all_of
#include <array>
#include <iostream>
#include <numeric>  // accumlate

using namespace std;

struct Test {
    string lft, rgt;
    char flag;  // -1, 0, 1

    bool IsPossible(char ch, int val) {
        int w1 = accumulate(lft.begin(), lft.end(), 0,
                            [ch, val](int& n, char c) { return n + val * (c == ch); });
        int w2 = accumulate(rgt.begin(), rgt.end(), 0,
                            [ch, val](int& n, char c) { return n + val * (c == ch); });
        char res = (w1 < w2 ? 1 : (w1 > w2 ? -1 : 0));
        return res == flag;
    }
};

pair<char, bool> Solve() {
    static constexpr int kTotalChar = 12;
    static constexpr int kTotalTest = 3;
    static array<Test, kTotalTest> tests;

    for (auto&& test : tests) {
        string s;
        cin >> test.lft >> test.rgt >> s;
        if (s == "even") {
            test.flag = 0;
        } else if (s == "up") {
            test.flag = -1;
        } else {
            test.flag = 1;
        }
    }

    // 窮舉所有可能性(共12*2=24種)
    for (char i = 'A'; i < 'A' + kTotalChar; i++) {
        if (all_of(tests.begin(), tests.end(), [i](Test& t) { return t.IsPossible(i, 1); })) {
            return {i, true};
        }
        if (all_of(tests.begin(), tests.end(), [i](Test& t) { return t.IsPossible(i, -1); })) {
            return {i, false};
        }
    }

    return {'Z', false};  // should not happen
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        pair<char, bool> res = Solve();
        cout << res.first << " is the counterfeit coin and it is "
             << (res.second ? "heavy" : "light") << ".\n";
    }
}
