#include <cmath>
#include <iostream>


int main() {
    int total_lights;
    while (std::cin >> total_lights && total_lights) {
        int sqrt_total_lights = std::sqrt(total_lights);
        // 判斷是否為平方數
        std::cout << (sqrt_total_lights * sqrt_total_lights == total_lights ? "yes" : "no") << "\n";
    }
}
