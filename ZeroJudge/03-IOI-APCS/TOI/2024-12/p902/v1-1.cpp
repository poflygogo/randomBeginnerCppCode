#include <iostream>

int main() {
    std::string s;
    std::getline(std::cin, s);
    int n;
    std::cin >> n;
    for (auto&& c : s) {
        if (std::isalpha(c)) {
            c = (c - (std::isupper(c) ? 'A' : 'a') + n) % 26 + (std::isupper(c) ? 'A' : 'a');
        }
    }
    std::cout << s;
}
