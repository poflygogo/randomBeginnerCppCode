#include <iomanip> // for setw()
#include <iostream>
#include <utility> // for swap()
#include <vector>
using namespace std;

void Print(vector<vector<short>> &arr, const short &size,
           const short kGap = 5) {
    for (short row = 0; row < size; row++) {
        for (short col = 0; col < size; col++) {
            cout << setw(kGap) << arr[row][col];
        }
        cout << endl;
    }
}

void Flip(vector<vector<short>> &arr, const short &size) {
    for (short row = 0; row < size; row++) {
        for (short col = row; col < size; col++) {
            swap(arr[row][col], arr[col][row]);
        }
    }
}

void Spiral(vector<vector<short>> &arr, const short &size) {
    short step = size - 1;
    short num = 1;
    short row = 0;
    short col = 0;

    while (step > 0) {
        for (short i = 0; i < step; i++) {
            arr[row][col++] = num++;
        }
        for (short i = 0; i < step; i++) {
            arr[row++][col] = num++;
        }
        for (short i = 0; i < step; i++) {
            arr[row][col--] = num++;
        }
        for (short i = 0; i < step; i++) {
            arr[row--][col] = num++;
        }
        row++;
        col++;
        step -= 2;
    }
    if (!step) {
        arr[row][col] = num;
    }
}

int main() {
    short t, size, mode;
    cin >> t;
    while (t--) {
        cin >> size >> mode;
        vector<vector<short>> arr(size);
        for (short i = 0; i < size; i++) {
            arr[i].resize(size);
        }
        Spiral(arr, size);
        if (mode == 2)
            Flip(arr, size);
        Print(arr, size);
        cout << endl;
    }
}
