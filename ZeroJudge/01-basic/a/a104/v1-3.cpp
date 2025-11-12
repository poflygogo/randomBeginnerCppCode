#include <iostream>
using namespace std;

// 插入排序法 Insertion Sort
void sort(int arr[], int arr_size) {
    for (int rgt = 1; rgt < arr_size; rgt++) {
        int tmp = arr[rgt];
        int idx = rgt - 1;
        while (idx >= 0 && arr[idx] > tmp) {
            arr[idx + 1] = arr[idx];
            idx--;
        }
        arr[idx + 1] = tmp;
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
// Zerojudge AC(9ms, 292KB)