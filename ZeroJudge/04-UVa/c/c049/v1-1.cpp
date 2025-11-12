#include <cmath>
#include <iostream>

int main() {
    int n;
    bool is_first_case = true;
    while (std::cin >> n) {
        if (!is_first_case) {
            puts("");
        }
        is_first_case = false;

        int diameter = 2 * n - 1;
        double radius = diameter / 2.0;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i * i + j * j < radius * radius) {
                    cnt++;
                }
            }
        }

        std::cout << "In the case n = " << n << ", " << 4 * diameter
                  << " cells contain segments of the circle.\n"
                  << "There are " << cnt * 4 << " cells completely contained in the circle.\n";
    }
}
