#include <algorithm>  // for_each, reverse
#include <iostream>

using namespace std;

bool IsPalindrome(const string& str) {
    string s;
    for_each(str.begin(), str.end(), [&s](char c) {
        if (isalnum(c)) {
            s += tolower(c);
        }
    });
    int lft = 0;
    int rgt = s.size() - 1;
    while (lft < rgt) {
        if (s[lft++] != s[rgt--]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    while (getline(cin, s)) {
        cout << s << '\n' << "-- is " << (IsPalindrome(s) ? "" : "not ") << "a palindrome\n";
    }
}
