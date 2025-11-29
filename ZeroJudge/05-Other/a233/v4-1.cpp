#include <iostream>
#include <vector>

// selection sort
// time complexity: O(n^2)
// space complexity: O(1)
void sort(std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        size_t min_idx = i;
        // find the minimum element in the unsorted part
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // swap the minimum element with the first element in the unsorted part
        std::swap(arr[i], arr[min_idx]);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    sort(arr);
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
}
