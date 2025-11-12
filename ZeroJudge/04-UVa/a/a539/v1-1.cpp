#include <iostream>
#include <vector>

int FlipSort(std::vector<int>& arr) {
    int cnt = 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int n;
    while (std::cin >> n) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        std::cout << "Minimum exchange operations : " << FlipSort(arr) << '\n';
    }
}
