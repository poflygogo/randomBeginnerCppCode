#include <iostream>
using namespace std;

// 希爾排序法 Shell Sort
// gap 採用 Knuth 序列
void sort(int arr[], int arr_size) {
    int gap = 1;
    while (gap < arr_size / 3) {
        gap = gap * 3 + 1;
    }
    while (gap >= 1) {
        for (int i = gap; i < arr_size; i++) {
            int curr = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > curr; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = curr;
        }
        gap /= 3;
    }
}

int main() {
    int arr_size;
    while (cin >> arr_size) {
        int arr[arr_size];
        for (int i = 0; i < arr_size; i++) {
            cin >> arr[i];
        }
        sort(arr, arr_size);
        for (int val : arr) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// 2025-09-21
// ZeroJudge AC(9ms, 340KB)
