#include <iostream>

using namespace std;

int main() {
    constexpr char black = '#';
    constexpr char white = '.';
    constexpr char board_size = 8;
    int n;
    while (cin >> n && n) {
        string a = string(n, black);
        string b = string(n, white);

        string line1 = a + b;  // #.
        string line2 = b + a;  // .#

        line1 += line1;  // #.#.
        line1 += line1;  // #.#.#.#.
        line1 += '\n';

        line2 += line2;  // .#.#
        line2 += line2;  // .#.#.#.#
        line2 += '\n';

        for (size_t i = 0; i < board_size; i++) {
            for (size_t j = 0; j < n; j++) {
                cout << (i % 2 == 0 ? line1 : line2);
            }
        }
        cout << '\n';
    }
}
