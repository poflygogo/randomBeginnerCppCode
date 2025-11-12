#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

// lazy me :P
using vv = std::vector<std::vector<int>>;
using v = std::vector<int>;

void ReadVectorData(const int rows, const int cols, vv& arr) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> arr[i][j];
        }
    }
}

int Similarity(const int rows, const int cols, const vv& p1, const vv& p2) {
    if (rows != p2.size() || cols != p2[0].size()) {
        return 0;
    }
    int same = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            same += p1[i][j] == p2[i][j];
        }
    }
    return same * 100 / (rows * cols);
}

vv Rotate(const vv& arr) {
    int rows = arr.size();
    int cols = arr[0].size();
    vv res(cols, v(rows));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[j][rows - 1 - i] = arr[i][j];
        }
    }
    return res;
}

int main() {
    int rows, cols;
    std::cin >> rows >> cols;
    vv photo1(rows, v(cols)), photo2(rows, v(cols));
    ReadVectorData(rows, cols, photo1);
    ReadVectorData(rows, cols, photo2);

    int max_val = 0;
    max_val = std::max(max_val, Similarity(rows, cols, photo1, photo2));
    for (int i = 0; i < 3; i++) {
        vv tmp = Rotate(photo2);
        max_val = std::max(max_val, Similarity(rows, cols, photo1, tmp));
        photo2 = tmp;
    }

    std::cout << max_val << '%';
}
