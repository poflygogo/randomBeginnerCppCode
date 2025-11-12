#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long MyPow(long long base, long long exponent) {
    long long res = 1;
    for (int i = 0; i < exponent; ++i) {
        res *= base;
    }
    return res;
}

long long Calc(const long long a, const long long b, const long long c, const long long d, const long long e,
               const long long f, const long long n) {
    return a * MyPow(n, 5) + b * MyPow(n, 4) + c * MyPow(n, 3) + d * MyPow(n, 2) + (e * n) + f;
}

int main() {
    const string kNoSolution = "N0THING! >\\\\\\<";
    const string kInfiniteSolution = "Too many... = =\"";
    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0) {
        cout << (f == 0 ? kInfiniteSolution : kNoSolution) << '\n';
    } else {
        vector<pair<long long, long long>> result;
        for (long long i = -35, j = -34; i < 35 && j < 36; ++i, ++j) {
            long long calc_i = Calc(a, b, c, d, e, f, i);
            long long calc_j = Calc(a, b, c, d, e, f, j);
            if (calc_i * calc_j < 0) {
                result.push_back({i, j});
            } else if (calc_i == 0) {
                result.push_back({i, i});
            }
        }
        if (result.empty()) {
            cout << kNoSolution << '\n';
        } else {
            for (const pair<long long, long long> item : result) {
                cout << item.first << ' ' << item.second << '\n';
            }
        }
    }
}
