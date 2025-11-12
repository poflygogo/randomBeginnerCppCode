#include <iostream>
#include <map>
using namespace std;

int Solve(int a, int b) {
    static map<int, int> cache;
    if (a > b) {
        swap(a, b);
    }

    int res = 0;
    for (int i = a; i <= b; i++) {
        int cnt = 0;
        int n = i;

        while (true) {
            if (cache.find(n) != cache.end()) {
                cnt += cache.at(n);
                break;
            }
            cnt++;
            if (n == 1) {
                break;
            } else if (n % 2) {
                n = 3 * n + 1;
            } else {
                n /= 2;
            }
        }

        cache[i] = cnt;
        res = max(res, cnt);
    }
    return res;
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        cout << a << ' ' << b << ' ' << Solve(a, b) << '\n';
    }
}
