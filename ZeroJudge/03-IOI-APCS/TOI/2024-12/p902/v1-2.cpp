#include <algorithm>
#include <iostream>

int main() {
    std::string s;
    std::getline(std::cin, s);
    int n;
    std::cin >> n;
    std::transform(s.begin(), s.end(), s.begin(), [n](char c) {
        if (std::isalpha(c)) {
            char k = isupper(c) ? 'A' : 'a';
            return char((c - k + n) % 26 + k);
        } else {
            return c;
        }
    });

    std::cout << s;
}
