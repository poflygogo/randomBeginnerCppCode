#include <algorithm>
#include <array>
#include <iostream>
#include <set>

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct Triangle {
    int a, b, c;

    Triangle(int x, int y, int z) : a(x), b(y), c(z) { simplify(); }
    void simplify() {
        int g = gcd(gcd(a, b), c);
        a /= g;
        b /= g;
        c /= g;
    }
};

bool operator<(const Triangle& a, const Triangle& b) {
    if (a.a != b.a) {
        return a.a < b.a;
    } else if (a.b != b.b) {
        return a.b < b.b;
    } else {
        return a.c < b.c;
    }
}

int main() {
    std::set<Triangle> memory;
    std::array<int, 3> tmp;
    int n;
    std::cin >> n;
    while (n--) {
        std::cin >> tmp[0] >> tmp[1] >> tmp[2];
        std::sort(tmp.begin(), tmp.end());
        memory.insert({tmp[0], tmp[1], tmp[2]});
    }
    std::cout << memory.size();
}
