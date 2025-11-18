#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> nums;
    string s;
    int max_size = 0;
    while (cin >> s && s != "0") {
        max_size = max(max_size, (int)s.size());
        reverse(s.begin(), s.end());
        nums.push_back(s);
    }
    s.clear();
    int carry = 0;
    for (size_t digit = 0; digit < max_size; digit++) {
        int sum = carry;
        for (size_t i = 0; i < nums.size(); i++) {
            if (digit < nums[i].size()) {
                sum += nums[i][digit] - '0';
            }
        }
        s += sum % 10 + '0';
        carry = sum / 10;
    }

    while (carry) {
        s += carry % 10 + '0';
        carry /= 10;
    }

    reverse(s.begin(), s.end());
    cout << s;
}
