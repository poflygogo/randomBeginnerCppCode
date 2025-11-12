#include <iostream>

void KnuthPermutation(const std::string& s, std::string& path, int idx = 0) {
    if (idx == s.size()) {
        std::cout << path << '\n';
        return;
    }
    for (int i = 0; i < path.size() + 1; i++) {
        path.insert(i, 1, s[idx]);
        KnuthPermutation(s, path, idx + 1);
        path.erase(i, 1);
    }
}

int main() {
    bool is_first_case = true;
    std::string s;
    while (std::getline(std::cin, s)) {
        if (!is_first_case) {
            std::cout << '\n';
        }

        is_first_case = false;
        std::string path;
        path.reserve(s.size());
        KnuthPermutation(s, path);
    }
}
