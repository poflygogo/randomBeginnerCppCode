#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>

int main() {
    std::array<double, 5> arr;
    std::cout << std::fixed << std::setprecision(2);
    while (std::cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4]) {
        auto it = std::find(arr.begin(), arr.end(), -1);
        int i = std::distance(arr.begin(), it);
        double a = arr[0];
        double b = arr[1];
        double c = arr[2];
        double d = arr[3];
        double e = arr[4];
        switch (i) {
            case 0:
                std::cout << (b + d) / e - c;
                break;
            case 1:
                std::cout << (a + c) * e - d;
                break;
            case 2:
                std::cout << (b + d) / e - a;
                break;
            case 3:
                std::cout << (a + c) / e - b;
                break;
            case 4:
                std::cout << (b + d) / (a + c);
                break;

            default:
                std::cout << "Uhhhh...";
                break;
        }
        std::cout << '\n';
    }
}
