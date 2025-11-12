#include <iostream>
#include <numeric>
#include <vector>

int main() {
    int n;
    int test_case = 1;
    while (std::cin >> n && n) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        int average = std::accumulate(arr.begin(), arr.end(), 0) / n;
        if (test_case > 1) {
            std::cout << '\n';
        }
        std::cout << "Set #" << test_case++ << "\nThe minimum number of moves is "
                  << std::accumulate(
                         arr.begin(), arr.end(), 0,
                         [&average](int a, int b) { return a + (b > average ? b - average : 0); })
                  << ".\n";
    }
}
