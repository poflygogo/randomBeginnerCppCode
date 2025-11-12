#include <iostream>
using namespace std;

// 選擇排序法 Selection Sort
void sort(int arr[], int arr_size) {
    for (int i = 0; i < arr_size - 1; i++) {
        int min_val_idx = i;
        for (int j = i + 1; j < arr_size; j++) {
            if (arr[j] < arr[min_val_idx]) {
                min_val_idx = j;
            }
        }
        if (i != min_val_idx) {
            int tmp = arr[i];
            arr[i] = arr[min_val_idx];
            arr[min_val_idx] = tmp;
        }
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
// ZeroJudge AC(11ms, 340KB)