// UVa 10954 - Add All
// ZeroJudge d221
// C++14

#include <functional>  // std::greater
#include <iostream>
#include <queue>  // std::priority_queue
#include <vector>

using ll = long long;

int main() {
    int n;
    while (std::cin >> n && n) {
        std::priority_queue<ll, std::vector<ll>, std::greater<ll>> min_heap;
        for (int _ = 0; _ < n; ++_) {
            ll val;
            std::cin >> val;
            min_heap.push(val);
        }

        ll sum = 0;
        for (int _ = 0; _ < n - 1; _++) {
            ll cost = min_heap.top();
            min_heap.pop();
            cost += min_heap.top();
            min_heap.pop();

            sum += cost;
            min_heap.push(cost);
        }

        std::cout << sum << '\n';
    }
}
