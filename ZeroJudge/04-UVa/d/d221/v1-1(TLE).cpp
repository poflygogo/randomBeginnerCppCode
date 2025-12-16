// UVa 10954 - Add All
// ZeroJudge d221
// C++14

#include <algorithm>   // std::sort
#include <functional>  // std::greater
#include <iostream>
#include <vector>

int main() {
    int n;
    while (std::cin >> n && n) {
        std::vector<int> arr(n);
        for (auto &&i : arr) { std::cin >> i; }

        std::sort(arr.begin(), arr.end(), std::greater<int>());
        int sum = 0;
        for (int _ = 0; _ < n - 1; _++) {
            int cost = arr.back();
            arr.pop_back();
            cost += arr.back();
            arr.pop_back();
            sum += cost;
            arr.push_back(cost);
            std::sort(arr.begin(), arr.end(), std::greater<int>());
        }

        std::cout << sum << '\n';
    }
}
