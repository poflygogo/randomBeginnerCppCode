#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> locate(n), power(n), locate_after(n);
    for (int i = 0; i < n; i++) {
        std::cin >> locate[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> power[i];
        locate_after[i] = locate[i] + power[i];
    }

    int max_locate = 0;
    for (int i = 0; i < n; i++) {
        if (max_locate >= locate[i]) {
            max_locate = std::max(max_locate, locate_after[i]);
        }
    }

    std::cout << max_locate;
}
