#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    vector<string> arr;
    arr.reserve(100);
    int width = 0;
    while (getline(cin, s)) {
        arr.push_back(s);
        width = max(width, s.size());
    }
    for (int i = 0; i < width; i++) {
        s = string(arr.size(), ' ');
        for (int j = arr.size() - 1; j >= 0; j--) {
            if (i < arr[j].size()) {
                s[arr.size() - j - 1] = arr[j][i];
            }
        }
        cout << s << '\n';
    }
}
