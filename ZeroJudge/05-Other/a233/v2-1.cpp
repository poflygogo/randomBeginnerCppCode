#include <iostream>
#include <utility>  // std::swap
#include <vector>

// bubble sort
// time complexity: O(n^2)
// space complexity: O(1)
void sort(std::vector<int>& arr) {
    bool swapped;
    for (size_t i = 0; i < arr.size(); ++i) {
        swapped = false;
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
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
