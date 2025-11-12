#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool Comp(const pair<char, int>& a, const pair<char, int>& b) {
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first > b.first;
    }
}

int main() {
    string s;
    map<char, int> counter;
    while (getline(cin, s)) {
        counter.clear();
        for (char c : s) {
            counter[c]++;
        }
        vector<pair<char, int>> arr(counter.begin(), counter.end());
        sort(arr.begin(), arr.end(), Comp);
        for (int i = 0; i < arr.size(); i++) {
            cout << (int)arr[i].first << ' ' << arr[i].second
                 << (i + 1 != arr.size() ? "\n" : "\n\n");
        }
    }
}
