#include <iostream>
#include <set>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::set<int> visited;
    while (n--) {
        int tmp;
        std::cin >> tmp;
        if (visited.find(tmp) == visited.end()) {
            std::cout << tmp << ' ';
            visited.insert(tmp);
        }
    }
}
