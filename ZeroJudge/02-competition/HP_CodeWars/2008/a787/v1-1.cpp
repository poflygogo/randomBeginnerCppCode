#include <algorithm>  // reverse
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string name, command;
    int width, heigh;
    while (cin >> name >> width >> heigh >> command) {
        cout << name << '\n';
        vector<string> arr(heigh);
        for (size_t i = 0; i < arr.size(); i++) {
            cin >> arr[i];
        }

        for (char c : command) {
            if (c == 'R') {
                for (auto&& line : arr) {
                    reverse(line.begin(), line.end());
                }
            } else if (c == 'I') {
                reverse(arr.begin(), arr.end());
            }
        }

        for (auto&& line : arr) {
            cout << line << '\n';
        }
    }
}
