#include <array>
#include <iostream>

using namespace std;
using hiaku = array<string, 3>;

int HiakuReview(const hiaku& arr) {
    static const string vowels = "aeiouy";
    static const array<int, 3> syllables = {5, 7, 5};
    for (int i = 0; i < arr.size(); i++) {
        int cnt = 0;
        bool flag = true;
        for (char c : arr[i]) {
            if (flag && vowels.find(c) != vowels.npos) {  // 連續的母音被視為同一個音節
                cnt++;
                flag = false;
            } else if (vowels.substr(0, 5).find(c) == vowels.substr(0, 5).npos) {
                flag = true;
            }
        }
        if (cnt != syllables[i]) {
            return i + 1;
        }
    }
    return 0;  // all pass
}

int main() {
    constexpr char sep = '/';
    hiaku arr;
    while (getline(cin, arr[0], sep) && getline(cin, arr[1], sep) && getline(cin, arr[2])) {
        if (arr[0] == "e" && arr[1] == "o" && arr[2] == "i") {
            break;
        }
        int res = HiakuReview(arr);
        if (res) {
            cout << res << '\n';
        } else {
            cout << 'Y' << '\n';
        }
    }
}
