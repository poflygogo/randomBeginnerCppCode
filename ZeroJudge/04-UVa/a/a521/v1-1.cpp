#include <iostream>

std::string NumJoin(const int st, const std::string& s) {
    std::string res;
    for (int i = 0; i < s.size(); i++) {
        res += std::to_string(st + s[i] - 'A');
    }
    return res;
}

void CalculatingYuanFen(const std::string& s) {
    for (int st = 1; st <= 10000; st++) {  // 0 < st <= 1e5
        std::string num = NumJoin(st, s);
        while (num.size() > 2) {
            for (int i = 1; i < num.size(); i++) {
                num[i - 1] = (num[i - 1] + num[i] - 2 * '0') % 10 + '0';
            }
            num.pop_back();
            if (num == "100") {
                std::cout << st;
                return;
            }
        }
    }
    std::cout << ":(";
}

int main() {
    std::string s;
    while (std::getline(std::cin, s)) {
        CalculatingYuanFen(s);
        std::cout << '\n';
    }
}
