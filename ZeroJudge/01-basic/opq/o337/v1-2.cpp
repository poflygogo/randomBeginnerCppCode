#include <iostream>
#include <unordered_set>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::unordered_set<int> visited;
    visited.reserve(n);
    while (n--) {
        int tmp;
        std::cin >> tmp;
        if (visited.find(tmp) == visited.end()) {
            std::cout << tmp << ' ';
            visited.insert(tmp);
        }
    }
}
