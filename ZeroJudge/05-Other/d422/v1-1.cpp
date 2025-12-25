// ZeroJudge d422 2.字串處理
// C++14

#include <cctype>  // isdigit
#include <iostream>
#include <string>

int main() {
    std::string s;
    while (std::getline(std::cin, s)) {
        int counter = 0;
        for (const char c : s) {
            if (std::isdigit(c)) {
                counter += c - '0';
            } else if (c == 'b') {
                std::cout << std::string(counter, ' ');
                counter = 0;
            } else if (c == '!') {
                std::cout << '\n';
            } else {
                std::cout << std::string(counter, c);
                counter = 0;
            }
        }
        std::cout << '\n';
    }
}
