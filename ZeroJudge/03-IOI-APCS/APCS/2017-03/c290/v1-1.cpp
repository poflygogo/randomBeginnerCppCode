// Zerojudge c290
// APCS 2017-03 1 秘密差
// c++14

#include <cstdlib>
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    int res = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        res += (s[i] - '0') * (i % 2 == 0 ? 1 : -1);
    }
    std::cout << abs(res) << '\n';
}
