#include <iostream>
#include <sstream>  // istringstream

using namespace std;

int main() {
    string line;
    istringstream iss;
    while (getline(cin, line) && line != "END") {
        iss.clear();
        iss.str(line);
        string s;
        while (iss >> s) {
            cout << (char)toupper(s.front());
        }
        cout << ' ' << s << '\n';
    }
}
