#include <iostream>
#include <vector>

int main() {
    int n, t;
    std::cin >> n >> t;
    std::vector<int> arr1(n), arr2(n);
    std::vector<bool> visited(n, true);
    for (int i = 0; i < n; i++) {
        std::cin >> arr1[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> arr2[i];
    }

    int eat = 0;
    while (visited[t]) {
        eat += arr2[t];
        visited[t] = false;
        t = arr1[t];
    }
    std::cout << eat;
}
