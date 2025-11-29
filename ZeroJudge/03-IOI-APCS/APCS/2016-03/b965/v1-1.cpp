// Zerojudge b965
// APCS 2016-03 2. 矩陣轉換
// C++14

#include <algorithm>  // reverse
#include <iostream>
#include <utility>  // swap(algorithm 也有)
#include <vector>

using namespace std;

// top-down flip
void mirrorMatrix(vector<vector<int>> &matrix, int &max_row, int &max_col) {
    reverse(matrix.begin(), matrix.begin() + max_row);
}

// anti-clockwise rotate
void rotateMatrix(vector<vector<int>> &matrix, int &max_row, int &max_col) {
    // mirrow [top-left -> bottom-right]
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = i + 1; j < matrix[i].size(); ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    swap(max_row, max_col);
    reverse(matrix.begin(), matrix.begin() + max_row);
}

int main() {
    int max_row, max_col, total_modes;
    cin >> max_row >> max_col >> total_modes;
    int max_size = max(max_row, max_col);

    // read matrix
    // 為了實現 in-place 操作，我們需要一個足夠大的矩陣，最好是正方形的
    // 不 in-place 也行，但空間複雜度會高一些
    vector<vector<int>> matrix(max_size, vector<int>(max_size));
    for (size_t i = 0; i < max_row; ++i) {
        for (size_t j = 0; j < max_col; ++j) {
            cin >> matrix[i][j];
        }
    }

    // read modes
    vector<int> modes(total_modes);
    for (size_t i = 0; i < total_modes; ++i) {
        cin >> modes[i];
    }

    // reverse modes
    for (int i = total_modes - 1; i >= 0; --i) {
        switch (modes[i]) {
        case 0:
            rotateMatrix(matrix, max_row, max_col);
            break;
        case 1:
            mirrorMatrix(matrix, max_row, max_col);
            break;
        }
    }

    // print result
    cout << max_row << ' ' << max_col << '\n';
    for (size_t i = 0; i < max_row; ++i) {
        for (size_t j = 0; j < max_col; ++j) {
            cout << matrix[i][j] << (j == max_col - 1 ? '\n' : ' ');
        }
    }
}
