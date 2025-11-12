#include <iostream>
using namespace std;

int main() {
    string s;
    bool flag = true;
    while (getline(cin, s)) {
        int i = s.find('"', 0);
        while (i != string::npos) {
            s.replace(i, 1, (flag ? "``" : "''"));
            flag = !flag;
            i = s.find("\"", i);
        }
        cout << s << '\n';
    }
}
