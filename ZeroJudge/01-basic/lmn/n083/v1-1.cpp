#include <algorithm>
#include <iostream>

int main() {
    const int p = 997;
    std::string s;
    while (std::cin >> s) {
        int sum = 0;
        for (int i = 0; i * 3 < s.size(); i++) {
            std::string tmp = s.substr(i * 3, 3);
            if (i % 2 != 0) {
                std::reverse(tmp.begin(), tmp.end());
            }
            sum += std::stoi(tmp);
        }
        sum %= p;
        std::cout << sum << '\n';
    }
}
