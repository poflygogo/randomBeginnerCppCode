#include <iostream>

int main() {
    int k, x1, y1, x2, y2;
    std::cin >> k >> x1 >> y1 >> x2 >> y2;

    int locate = 0;
    while (k > 0) {
        locate += k;
        if (locate % x1 == 0) k -= y1;
        if (locate % x2 == 0) k -= y2;
    }
    std::cout << locate;
}
