#include <algorithm>
#include <iostream>

int main() {
    const std::string keyboard = " `1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./ ";
    std::string s;
    while (getline(std::cin, s)) {
        std::transform(s.begin(), s.end(), s.begin(),
                       [&keyboard](char c) { return keyboard[std::max(0, (int)keyboard.find(c) - 1)]; });
        std::cout << s << '\n';
    }
}
