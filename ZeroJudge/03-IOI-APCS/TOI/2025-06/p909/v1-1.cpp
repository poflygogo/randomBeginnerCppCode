// ZeroJudge p909. 窗花 (Tracery)
// TOI 練習賽 2025-06 新手組 第1題
// C++14

#include <iostream>
#include <vector>

void printRow(const std::vector<int> &arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << ' ';
    }
    for (int i = arr.size() - 1; i >= 0; --i) {
        std::cout << arr[i] << (i != 0 ? ' ' : '\n');
    }
}

int main() {
    int max_row, max_col;
    std::cin >> max_col >> max_row;

    std::vector<std::vector<int>> matrix(max_row, std::vector<int>(max_col));
    for (auto &&row : matrix) {
        for (auto &&col : row) {
            std::cin >> col;
        }
    }

    for (size_t r = 0; r < max_row; ++r) {
        printRow(matrix[r]);
    }

    for (int r = max_row - 1; r >= 0; --r) {
        printRow(matrix[r]);
    }
}
