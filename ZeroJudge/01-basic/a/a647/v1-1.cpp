#include <iomanip>
#include <iostream>
using namespace std;

void MyRound(int &num) {
    if (num > 0 && num % 10 >= 5) {
        num += 10;
    } else if (num < 0 && num % 10 <= -5) {
        num -= 10;
    }
}

// 避免浮點數誤差的最佳作法，就是幹你娘不要用浮點數

int main() {
    const string kDispose = "% dispose\n";
    const string kKeep = "% keep\n";
    short n;
    int m, p, res, decimal;
    string res_text;
    cin >> n;
    while (n--) {
        cin >> m >> p;
        res = 100000 * (p - m) / m;
        if (res >= 10000 || res <= -7000) {
            res_text = kDispose;
        } else {
            res_text = kKeep;
        }
        MyRound(res);
        if (res < 0) {
            cout << '-';
        }
        cout << abs(res / 1000);
        cout << '.' << setw(2) << setfill('0') << abs(res % 1000 / 10);
        cout << res_text;
    }
}
