// Zerojudge e313
// APCS 2018-10 1 最少相異字母
// c++14

#include <iostream>
#include <string>
#include <unordered_set>

int calcDiff(const std::string &s) {
    std::unordered_set<char> set;
    for (const char c : s) {
        set.insert(c);
    }
    return int(set.size());
}

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    n--;
    int min_diff = calcDiff(s);
    while (n--) {
        std::string tmp;
        std::cin >> tmp;
        int diff = calcDiff(tmp);
        if (diff < min_diff || (diff == min_diff && tmp < s)) {
            min_diff = diff;
            s = tmp;
        }
    }
    std::cout << s;
}
