#include <iostream>
using namespace std;

int main() {
    string s;
    while (cin >> s && s != "-1") {
        if (s.substr(0, 2) == "0x") {
            cout << dec << stoi(s.substr(2), nullptr, 16) << '\n';
        } else {
            cout << hex << uppercase << "0x" << stoi(s) << '\n';
        }
    }
}
