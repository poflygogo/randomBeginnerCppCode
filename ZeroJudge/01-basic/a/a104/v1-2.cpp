#include <iostream>
using namespace std;

// 氣泡排序法 Bubble Sort
void sort(int arr[], int arr_size) {
    for (int i = 0; i < arr_size - 1; i++) {
        for (int j = i + 1; j < arr_size; j++) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
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