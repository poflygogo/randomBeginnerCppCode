#include <algorithm>
#include <iostream>
using namespace std;

bool IsPalindrome(const long long n) {
    string s = to_string(n);
    auto lft = s.begin();
    auto rgt = s.end() - 1;
    while (lft < rgt) {
        if ((*lft) != (*rgt)) {
            return false;
        }
        lft++;
        rgt--;
    }
    return true;
}

int ReverseNum(const long long n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stoi(s);
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        long long num;
        cin >> num;
        int cnt = 0;
        do {
            num += ReverseNum(num);
            cnt++;
        } while (!IsPalindrome(num));
        cout << cnt << ' ' << num << '\n';
    }
}
