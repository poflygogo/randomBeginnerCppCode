#include <iostream>
using namespace std;

int main() {
    int num;
    while (cin >> num) {
        cout << "TERM " << num << " IS ";
        int stage = 1;
        while (stage < num) {
            num -= stage;
            stage++;
        }

        if (stage % 2 == 0) {
            cout << num << '/' << stage - num + 1 << '\n';
        } else {
            cout << stage - num + 1 << '/' << num << '\n';
        }
    }
}
