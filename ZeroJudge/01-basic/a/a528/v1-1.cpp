#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool MyCompare(const string &a, const string &b) {
    bool a_is_negative = a.front() == '-';
    bool b_is_negative = b.front() == '-';

    // 兩數皆為正時
    // 長度越長，代表數字越大
    // 若長度相等，則字典序大的數字較大
    // 兩數皆為負時，條件剛好反過來

    if (!a_is_negative && !b_is_negative) {         // 皆為正
        return a.size() == b.size() ? a < b : a.size() < b.size();
    } else if (a_is_negative && !b_is_negative) {   // 只有 a 是負數
        return true;
    } else if (!a_is_negative && b_is_negative) {   // 只有 b 是負數
        return false;
    } else {                                        // 皆為負，反過來做
        return a.size() == b.size() ? a > b : a.size() > b.size();
    }
}

int main() {
    short num;
    while (cin >> num) {
        vector<string> arr(num);
        for (short i = 0; i < num; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end(), MyCompare);
        for (const string &ele : arr) {
            cout << ele << '\n';
        }
    }
}
