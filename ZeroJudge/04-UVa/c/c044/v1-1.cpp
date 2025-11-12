#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

int main() {
    array<pair<int, int>, 26> counter;
    for (int i = 0; i < 26; i++) {
        counter[i].second = -i;
    }
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string s;
        getline(cin, s);
        for (char c : s) {
            if (isalpha(c)) {
                counter[tolower(c) - 'a'].first++;
            }
        }
    }
    sort(counter.begin(), counter.end(), greater<pair<int, int>>());
    for (const pair<int, int>& item : counter) {
        if (item.first == 0) {
            break;
        }
        cout << (char)(-item.second + 'A') << ' ' << item.first << '\n';
    }
}
