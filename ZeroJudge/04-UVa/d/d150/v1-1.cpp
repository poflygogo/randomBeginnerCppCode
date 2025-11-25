#include <algorithm>   // sort
#include <functional>  // greater<int>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        for (size_t i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
        std::sort(arr.begin(), arr.end(), std::greater<int>());  // sort in descending order
        int sum = 0;
        for (size_t i = 2; i < n; i += 3) {
            sum += arr[i];
        }
        std::cout << sum << '\n';
    }
}
