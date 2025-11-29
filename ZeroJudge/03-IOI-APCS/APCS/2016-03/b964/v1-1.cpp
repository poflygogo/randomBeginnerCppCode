// Zerojudge b964
// APCS 2016-03 1. 成績指標
// C++14

#include <algorithm>  // sort, for_each
#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    int max_bad = -1;
    int min_good = 101;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        if (arr[i] >= 60) {
            min_good = std::min(min_good, arr[i]);
        } else {
            max_bad = std::max(max_bad, arr[i]);
        }
    }
    std::sort(arr.begin(), arr.end());
    std::for_each(arr.begin(), arr.end(), [](int& x) { std::cout << x << ' '; });
    std::cout << '\n';
    std::cout << (max_bad == -1 ? "best case" : std::to_string(max_bad)) << '\n';
    std::cout << (min_good == 101 ? "worst case" : std::to_string(min_good)) << '\n';
}
