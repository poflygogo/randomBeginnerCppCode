#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, k;
    string s;
    map<int, int> keywords;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        keywords[t - 1] = i;
    }
    cin >> s >> k;

    for (int cnt = 0; cnt < k; cnt++) {
        string tmp = string(n, ' ');
        for (int i = 0; i < s.size(); i++) {
            tmp[keywords[i]] = s[i];
        }
        s = tmp;
    }
    cout << s;
}
