#include <iostream>

int ExcessiveSpaceRemover(std::string& s) {
    static const std::string kFrom = std::string(2, ' ');
    static const std::string kTo = std::string(1, ' ');
    int cnt = 0;
    int pos;
    while ((pos = s.find(kFrom)) != std::string::npos) {
        do {
            s.replace(pos++, kFrom.size(), kTo);
        } while ((pos = s.find(kFrom, pos)) != std::string::npos);
        cnt++;
    }
    return cnt;
}

int main() {
    std::string s;
    while (std::getline(std::cin, s)) {
        std::cout << ExcessiveSpaceRemover(s) << '\n';
    }
}
