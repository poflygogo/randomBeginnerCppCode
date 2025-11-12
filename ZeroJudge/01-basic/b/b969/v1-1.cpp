#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    string hello;
    getline(cin, hello);
    hello += ", ";
    while (ss >> s) {
        cout << hello << s << '\n';
    }
}
