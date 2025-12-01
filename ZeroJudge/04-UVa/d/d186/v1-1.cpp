// Zerojudge d186
// UVa 11461 - Square Numbers
// c++14

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    // initialize
    constexpr int kLimit = 100000;
    std::vector<int> square;
    for (int i = 1; i * i <= kLimit; ++i) {
        square.push_back(i * i);
    }

    int a, b;
    while (std::cin >> a >> b && a || b) {
        auto it1 = std::lower_bound(square.begin(), square.end(), a);
        auto it2 = std::upper_bound(square.begin(), square.end(), b);
        std::cout << std::distance(it1, it2) << '\n';
    }
}
