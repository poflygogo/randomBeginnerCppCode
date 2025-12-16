// UVa 11455 - Behold my quadrangle
// ZeroJudge d260
// C++14

#include <algorithm>
#include <array>
#include <iostream>

int main() {
    std::array<int, 4> arr;
    int t;
    std::cin >> t;
    while (t--) {
        for (auto &&i : arr) { std::cin >> i; }
        std::sort(arr.begin(), arr.end());

        if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3]) {
            std::cout << "square";
        } else if (arr[0] == arr[1] && arr[2] == arr[3]) {
            std::cout << "rectangle";
        } else if (arr[0] + arr[1] + arr[2] > arr[3]) {
            std::cout << "quadrangle";
        } else {
            std::cout << "banana";
        }
        std::cout << '\n';
    }
}
