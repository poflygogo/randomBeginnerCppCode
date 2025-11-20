#include <iostream>
#include <string>

using namespace std;

int ToDays(int d, int m, int y) { return d + m * 30 + y * 365; }

int main() {
    int t;
    cin >> t;
    for (int test_case = 1; test_case <= t; ++test_case) {
        string date1, date2;
        cin >> date1 >> date2;
        int d1 = stoi(date1.substr(0, 2));
        int m1 = stoi(date1.substr(3, 2));
        int y1 = stoi(date1.substr(6, 4));
        int d2 = stoi(date2.substr(0, 2));
        int m2 = stoi(date2.substr(3, 2));
        int y2 = stoi(date2.substr(6, 4));

        cout << "Case #" << test_case << ": ";

        if (y1 < y2 || (y1 == y2 && m1 < m2) || (y1 == y2 && m1 == m2 && d1 < d2)) {
            cout << "Invalid birth date" << '\n';
            continue;
        }

        int age = (ToDays(d1, m1, y1) - ToDays(d2, m2, y2)) / 365;
        if (age > 130) {
            cout << "Check birth date" << '\n';
        } else {
            cout << age << '\n';
        }
    }
}
