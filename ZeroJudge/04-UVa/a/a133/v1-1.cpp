#include <iostream>
#include <vector>

int LCS(std::vector<int>& a, std::vector<int>& b) {
    if (a.size() < b.size()) {
        std::swap(a, b);
    }

    int m = a.size();
    int n = b.size();

    std::vector<int> prev(n + 1, 0);
    std::vector<int> curr(n + 1, 0);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                curr[j] = prev[j - 1] + 1;
            } else {
                curr[j] = std::max(prev[j], curr[j - 1]);
            }
        }
        std::swap(prev, curr);
    }
    return prev[n];
}

int main() {
    int n1, n2;
    int test_case = 1;
    while (std::cin >> n1 >> n2 && n1 && n2) {
        std::vector<int> arr1(n1), arr2(n2);
        for (int i = 0; i < n1; i++) {
            std::cin >> arr1[i];
        }
        for (int i = 0; i < n2; i++) {
            std::cin >> arr2[i];
        }

        std::cout << "Twin Towers #" << test_case++ << "\nNumber of Tiles : " << LCS(arr1, arr2)
                  << "\n\n";
    }
}
