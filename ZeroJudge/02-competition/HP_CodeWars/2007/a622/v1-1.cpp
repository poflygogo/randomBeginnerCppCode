#include <iostream>
#include <vector>

int main() {
    std::string name;
    std::vector<std::string> arr;
    arr.reserve(16);
    int max_width = 0;
    while (std::getline(std::cin, name) && name != "END") {
        arr.push_back(name);
        max_width = std::max(max_width, (int)name.size());
    }
    for (int i = 0; i < max_width; i++) {
        for (auto&& s : arr) {
            std::cout << (i < s.size() ? s[i] : ' ') << "  ";
        }
        std::cout << '\n';
    }
}
