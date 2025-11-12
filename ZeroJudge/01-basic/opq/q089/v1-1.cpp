#include <iostream>

int main() {
    using namespace std;

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << string(n - i, ' ');
        for (int j = 0; j < i; j++) {
            cout << "* ";
        }
        cout << '\n';
    }

    string t = string(n - 2, ' ') + "| |";
    for (int i = 0; i < n / 2; i++) {
        cout << t << '\n';
    }

    cout << '\\' << string((n + (n - 1) - 2), '_') << '/';
}
