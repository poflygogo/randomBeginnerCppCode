#include <iostream>
using namespace std;

int main() {
  unsigned int row, col;
  while (cin >> row >> col) {
    int arr[row][col];
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        cin >> arr[r][c];
      }
    }
    int arr2[col][col];
    for (int r = 0; r < col; r++) {
      for (int c = 0; c < row; c++) {
        arr2[r][c] = arr[c][r];
      }
    }
    const char SPACE = ' ';
    for (int r = 0; r < col; r++) {
      for (int c = 0; c < row - 1; c++) {
        cout << arr2[r][c] << SPACE;
      }
      cout << arr2[r][row - 1] << endl;
    }
  }
}
