#include <iostream>

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        int a, b;
        std::cin >> a >> b;
        std::cout << (a > b ? '>' : (a < b ? '<' : '=')) << '\n';
    }
}
