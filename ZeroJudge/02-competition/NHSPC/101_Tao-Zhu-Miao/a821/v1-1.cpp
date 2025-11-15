#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int n, r;
    string a, b;
    map<string, set<string>> counter;
    cin >> n >> r;
    while (cin >> a >> b) {
        counter[a].insert(b);
    }

    string res;
    for (auto&& i : counter) {
        if (i.second.size() == n - 1) {
            res = i.first;
            break;
        }
    }
    cout << res;
}
