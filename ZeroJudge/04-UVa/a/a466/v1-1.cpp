#include <iostream>

int OneTwoThree(const std::string& s) {
    if (s.size() == 5) {
        return 3;
    }

    std::string one = "one";
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum += one[i] != s[i];
    }
    return sum <= 1 ? 1 : 2;
}

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        std::string s;
        std::cin >> s;
        std::cout << OneTwoThree(s) << '\n';
    }
}
