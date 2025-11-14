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
    string e = s;
    reverse(e.begin(), e.end());
    return s == e;
}

int main() {
    string s;
    while (getline(cin, s)) {
        cout << s << '\n' << "-- is " << (IsPalindrome(s) ? "" : "not ") << "a palindrome\n";
    }
}
