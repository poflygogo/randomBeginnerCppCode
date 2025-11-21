#include <iostream>
#include <string>
#include <vector>

using namespace std;

int year_mod(string& year, int mod) {
    int ans = 0;
    for (char c : year) {
        ans = (ans * 10 + c - '0') % mod;
    }
    return ans;
}

vector<string> gulamatu(string& year) {
    vector<string> ans;
    bool is_leap = false;
    if (year_mod(year, 4) == 0 && year_mod(year, 100) != 0 || year_mod(year, 400) == 0) {
        ans.push_back("leap");
        is_leap = true;
    }
    if (year_mod(year, 15) == 0) {
        ans.push_back("huluculu festival");
    }
    if (is_leap && year_mod(year, 55) == 0) {
        ans.push_back("bulukulu festival");
    }
    if (ans.empty()) {
        ans.push_back("an ordinary");
    }
    return ans;
}

int main() {
    string year;  // big integer
    while (cin >> year) {
        for (const string& s : gulamatu(year)) {
            cout << "This is " << s << " year." << '\n';
        }
        cout << '\n';
    }
}
