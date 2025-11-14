#include <iostream>

using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        s.back() = ' ';
        size_t i = s.find_last_of('=');
        i = s.find_last_of(' ', i);
        i = s.find_last_of(' ', i - 1);
        cout << s.substr(i) << s.substr(0, i) << ";\n";
    }
}
