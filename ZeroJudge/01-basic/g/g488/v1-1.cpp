#include <iostream>

int covid(int n) {
    if (n == 1) {
        return 1;
    }
    return covid(n - 1) + n * n - n + 1;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << covid(n);
}
