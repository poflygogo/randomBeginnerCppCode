#include <climits>  // INT_MAX
#include <iostream>
#include <map>
#include <sstream>  // istringstream

using namespace std;

int main() {
    map<string, string> l337;
    string line;
    cin.ignore(INT_MAX, '\n');
    while (getline(cin, line) && line != "[1337]") {
        size_t i = line.find(':');
        l337[line.substr(0, i)] = line.substr(i + 1);
    }

    istringstream iss;
    while (getline(cin, line) && line != "[3ND]") {
        iss.clear();
        iss.str(line);
        string s;
        while (iss >> s) {
            if (l337.find(s) != l337.end()) {
                cout << l337.at(s) << ' ';
            } else {
                cout << s << ' ';
            }
        }
        cout << '\n';
    }
}
