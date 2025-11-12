#include <iomanip>
#include <iostream>
#include <map>

using namespace std;

char SoundexGet(char c) {
    switch (c) {
        case 'B':
        case 'P':
        case 'F':
        case 'V':
            return '1';
        case 'C':
        case 'S':
        case 'K':
        case 'G':
        case 'J':
        case 'Q':
        case 'X':
        case 'Z':
            return '2';
        case 'D':
        case 'T':
            return '3';
        case 'L':
            return '4';
        case 'M':
        case 'N':
            return '5';
        case 'R':
            return '6';
        default:
            return 0;
    }
}

int main() {
    cout << "NAME" << string(21, ' ') << "SOUNDEX CODE" << '\n';
    cout << left;
    string name;
    while (getline(cin, name)) {
        string s_code;
        s_code.reserve(4);
        s_code += name.front();
        for (int i = 1; i < name.size(); i++) {
            if (SoundexGet(name[i]) && SoundexGet(name[i]) != SoundexGet(name[i - 1])) {
                s_code += SoundexGet(name[i]);
                if (s_code.size() == 4) {
                    break;
                }
            }
        }
        cout << setw(0) << setfill(' ') << string(10, ' ');
        cout << setw(20) << name << string(5, ' ');
        cout << setw(4) << setfill('0') << s_code << '\n';
    }
    cout << string(19, ' ') << "END OF OUTPUT";
}
