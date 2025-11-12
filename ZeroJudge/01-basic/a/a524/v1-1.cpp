#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void PossiblePassword(const short &num) {
    string s = "";
    for (short i = num; i > 0; i--) {
        s += '0' + i;
    }
    do {
        cout << s << '\n';
    } while (prev_permutation(s.begin(), s.end()));
}

int main() {
    short num;
    while (cin >> num) {
        PossiblePassword(num);
    }
}
