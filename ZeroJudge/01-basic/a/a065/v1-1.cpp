#include <iostream>
using namespace std;

int main() {
    const int SIZE = 7;
    char s[SIZE];
    cin >> s;
    for (int i = 0; i < SIZE - 1; i++) {
        cout << abs(s[i] - s[i + 1]);
    }
    cout << endl;
}