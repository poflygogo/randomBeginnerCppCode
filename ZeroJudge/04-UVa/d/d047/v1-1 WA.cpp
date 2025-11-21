#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> gulamatu(int year) {
    vector<string> ans;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        ans.push_back("leap");
    }
    if (year % 15 == 0) {
        ans.push_back("huluculu festival");
    }
    if (year % 55 == 0) {
        ans.push_back("bulukulu festival");
    }
    if (ans.empty()) {
        ans.push_back("an ordinary");
    }
    return ans;
}

int main() {
    int year;
    while (cin >> year) {
        for (const string& s : gulamatu(year)) {
            cout << "This is " << s << " year." << '\n';
        }
        cout << '\n';
    }
}
