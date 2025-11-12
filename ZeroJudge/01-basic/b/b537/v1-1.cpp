#include <array>
#include <iostream>
using namespace std;

// 題目說數字最大是 60
const int kLimit = 60;
array<array<long long, kLimit + 1>, kLimit + 1> cache = {};

long long Solution(int a, int b) {
    // 有算過的就直接返回之前算的結果
    if (cache[a][b] != 0) {
        return cache[a][b];
    } else if (a == b) {
        cache[a][b] = 1;
        return 1;
    }

    long long result;
    if (a > b) {
        result = Solution(a - b, b) * 2;
    } else {
        result = Solution(b, a) + 1;
    }
    cache[a][b] = result;
    return result;
}

int Gcd(int a, int b) { return b == 0 ? a : Gcd(b, a % b); }

int main() {
    int a, b, g;
    while (cin >> a >> b) {
        g = Gcd(a, b);
        a /= g;
        b /= g;
        cout << Solution(a, b) << '\n';
    }
}
