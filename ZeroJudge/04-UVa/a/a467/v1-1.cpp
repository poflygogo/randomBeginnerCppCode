#include <iostream>
#include <numeric>

int main() {
    std::string s;
    while (std::cin >> s && s != "~") {
        std::string bin;
        bool flag = s.size() == 1;
        while (std::cin >> s && s != "#") {
            if (s.size() <= 2) {
                flag = s.size() == 1;
            } else {
                bin += std::string(s.size() - 2, (flag ? '1' : '0'));
            }
        }
        std::cout << std::stoi(bin, nullptr, 2) << '\n';
    }
}
