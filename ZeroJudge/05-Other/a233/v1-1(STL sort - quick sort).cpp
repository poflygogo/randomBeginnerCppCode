#include <algorithm>
#include <iostream>
#include <vector>

// STL sort -> quick sort
// time complexity: O(n log n)
// space complexity: O(log n)

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
}
