// UVa 11313 - Gourmet Games
// ZeroJudge d258
// C++14

#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int a, b;
        std::cin >> a >> b;
        if ((a - 1) % (b - 1) == 0) {
            std::cout << (a - 1) / (b - 1) << '\n';
        } else {
            std::cout << "cannot do this\n";
        }
    }
}
