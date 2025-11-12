#include <array>
#include <iostream>
#include <numeric>

using namespace std;

struct Test {
    string lft, rgt;
    char flag;
};

template <std::size_t N>
bool check(const array<Test, N>& tests, char ch, int val) {
    for (auto&& t : tests) {
        int w1 = accumulate(t.lft.begin(), t.lft.end(), 0,
                            [ch, val](int& n, char c) { return n + val * (c == ch); });
        int w2 = accumulate(t.rgt.begin(), t.rgt.end(), 0,
                            [ch, val](int& n, char c) { return n + val * (c == ch); });
        if (!((w1 == w2 && t.flag == 0) || (w1 > w2 && t.flag == -1) || (w1 < w2 && t.flag == 1))) {
            return false;
        }
    }
    return true;
}

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
        if (check(tests, i, 1)) {  // means heavy
            return {i, true};
        }
        if (check(tests, i, -1)) {  // means light
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
