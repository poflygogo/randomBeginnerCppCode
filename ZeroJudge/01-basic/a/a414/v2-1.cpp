#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int num, cnt;
    while (cin >> num && num) {
        for (cnt = 0; num & 1; cnt++) {
            num >>= 1;
        }
        cout << cnt << endl;
    }
}
