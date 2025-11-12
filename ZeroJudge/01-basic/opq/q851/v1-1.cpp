#include <iostream>

int main() {
    std::string s;
    while (std::getline(std::cin, s)) {
        int size = s.size();
        int i = s.find(' ');

        while (i < size) {
            int j = std::min(s.find_first_not_of(' ', i), s.size());
            int diff = j - i;
            s.replace(i, diff - 1, std::string(diff - 1, '*'));
            i = s.find(' ', j);
        }

        if (s.front() == ' ') {
            s.front() = '*';
        }
        if (s.back() == ' ') {
            s.back() = '*';
        }

        std::cout << s << '\n';
    }
}
