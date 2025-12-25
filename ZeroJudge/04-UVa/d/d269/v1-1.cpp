// UVa 11579 - Triangle Trouble
// ZeroJudge d269
// C++14

#include <algorithm>   // sort
#include <cmath>       // sqrt
#include <functional>  // greater
#include <iomanip>     // precious
#include <ios>         // fixed
#include <iostream>
#include <vector>

// Greedy
// 已知周長相等的情況下，正三角形的面積是最大的
// 故此處只檢查相鄰的三條邊即可(長度相近)
// 從最大的三條邊開始檢查，一旦發現任一符合條件的組合，就可以直接計算面積並退出循環
double findMaxSize(std::vector<double> &arr) {
    double max_area = 0.0;

    for (size_t i = 0; i + 2 < arr.size(); ++i) {
        double a = arr[i];
        double b = arr[i + 1];
        double c = arr[i + 2];

        if (a < b + c) {
            double s = (a + b + c) / 2.0;
            double area = sqrt(s * (s - a) * (s - b) * (s - c));
            return std::max(max_area, area);
        }
    }

    return max_area;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<double> arr(n);
        for (auto &&i : arr) { std::cin >> i; }

        std::sort(arr.begin(), arr.end(), std::greater<int>());

        double max_area = findMaxSize(arr);

        std::cout << std::fixed << std::setprecision(2) << max_area << '\n';
    }
}
