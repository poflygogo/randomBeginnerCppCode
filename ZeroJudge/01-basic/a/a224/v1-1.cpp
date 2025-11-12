#include <array>
#include <cctype>   // isalpha 和 toupper 會用到
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    s.reserve(1000);
    while (cin >> s) {
        array<bool, 26> arr = {false};
        for (char c : s) {
            if (!isalpha(c)) {
                continue;
            }
            int idx = toupper(c) - 'A';
            arr[idx] ^= true;
        }
        int sum = 0;
        for (bool i : arr) {
            if (i) {
                sum++;
            }
        }
        if (sum <= 1) {
            cout << "yes !" << endl;
        } else {
            cout << "no..." << endl;
        }
    }
}