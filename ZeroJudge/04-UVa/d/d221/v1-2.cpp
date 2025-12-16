// UVa 10954 - Add All
// ZeroJudge d221
// C++14

#include <algorithm>   // std::sort, std::lower_bound
#include <functional>  // std::greater
#include <iostream>
#include <vector>

int main() {
    int n;
    while (std::cin >> n && n) {
        std::vector<int> arr(n);
        for (auto &&i : arr) { std::cin >> i; }

        std::sort(arr.begin(), arr.end(), std::greater<int>());

        // 資料型態務必用 long long
        long long sum = 0;
        for (int _ = 0; _ < n - 1; _++) {
            int cost = arr.back();
            arr.pop_back();
            cost += arr.back();
            arr.pop_back();

            sum += cost;

            auto it = std::lower_bound(arr.begin(), arr.end(), cost, std::greater<int>());
            arr.insert(it, cost);
        }

        std::cout << sum << '\n';
    }
}
