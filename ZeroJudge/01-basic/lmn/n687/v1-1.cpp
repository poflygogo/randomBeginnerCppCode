#include <iostream>

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int xa = std::max(x1, x3);
    int xb = std::min(x2, x4);
    int ya = std::max(y1, y3);
    int yb = std::min(y2, y4);

    if (xa >= xb || ya >= yb) {
        std::cout << "banana";
    } else {
        std::cout << (xb - xa) * (yb - ya);
    }
}
