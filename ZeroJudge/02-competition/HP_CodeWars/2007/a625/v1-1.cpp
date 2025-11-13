#include <iostream>

int main() {
    double n;
    while (std::cin >> n) {
        double cnt = 1.0;
        double harmonic = 0.5;
        while (n > harmonic) {
            cnt += 1.0;
            harmonic += 1 / (cnt + 1);
        }
        std::cout << cnt << " card(s)\n";
    }
}
