#include <iostream>

std::string SepAndJoin(const std::string& s, const char sep = ' ') {
    std::string res;
    res.reserve(s.size());
    for (char c : s) {
        if (c != sep) {
            res += c;
        }
    }
    return res;
}

int main() {
    int n;
    std::string got, expected;
    std::cin >> n;
    std::cin.ignore();
    for (int test_case = 1; test_case <= n; test_case++) {
        std::getline(std::cin, got);
        std::getline(std::cin, expected);
        std::cout << "Case " << test_case << ": ";
        if (got == expected) {
            std::cout << "Yes" << '\n';
        } else if (SepAndJoin(got) == expected) {
            std::cout << "Output Format Error" << '\n';
        } else {
            std::cout << "Wrong Answer" << '\n';
        }
    }
}
