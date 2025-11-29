// ZeroJudge c461
// APCS 2017-10 1 邏輯運算子 (Logic Operators)
// C++14

#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    bool is_and = ((bool)a && (bool)b) == (bool)c;
    bool is_or = ((bool)a || (bool)b) == (bool)c;
    bool is_xor = ((bool)a ^ (bool)b) == (bool)c;

    if (is_and) {
        std::cout << "AND\n";
    }
    if (is_or) {
        std::cout << "OR\n";
    }
    if (is_xor) {
        std::cout << "XOR\n";
    }
    if (!(is_and || is_or || is_xor)) {
        std::cout << "IMPOSSIBLE\n";
    }
}
