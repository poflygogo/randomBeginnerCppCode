// UVa 11462 - Age Sort
// ZeroJudge 190
// C++14

#include <array>
#include <iostream>

int main() {
    // counting sort
    constexpr int kLimit = 100;
    std::array<int, kLimit> arr;
    int n;
    while (std::cin >> n) {
        arr.fill(0);

        while (n--) {
            int age;
            std::cin >> age;
            arr.at(age)++;
        }

        for (int i = 0; i < kLimit; i++) {
            while (arr.at(i)--) { std::cout << i << ' '; }
        }
        std::cout << '\n';
    }
}
