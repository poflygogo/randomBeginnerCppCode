#include <iostream>

using namespace std;

int main() {
    string s;
    while (getline(cin, s) && s != "END") {
        size_t i = s.find_first_not_of(' ');
        while (i != s.npos) {
            cout << (char)toupper(s[i]);
            i = s.find_first_of(' ', i);
            i = s.find_first_not_of(' ', i);
        }

        i = s.find_last_of(' ') + 1;
        cout << ' ' << s.substr(i) << '\n';
    }
}
