#include <iostream>
using namespace std;

// 合併排序法 Merge Sort
void sort(int arr[], int arr_size);
void merge_sort(int arr[], int lft, int rgt);
void merge(int arr[], int lft, int mid, int rgt);

void merge(int arr[], int lft, int mid, int rgt) {
    int arr_lft_size = mid - lft + 1; ///< 陣列1的大小
    int arr_rgt_size = rgt - mid;     ///< 陣列2的大小

    int arr_lft[arr_lft_size]; ///< 陣列1
    int arr_rgt[arr_rgt_size]; ///< 陣列2

    for (int i = 0; i < arr_lft_size; i++) {
        arr_lft[i] = arr[lft + i];
    }
    for (int i = 0; i < arr_rgt_size; i++) {
        arr_rgt[i] = arr[mid + i + 1];
    }

    // 合併回主陣列
    int lft_idx = 0; ///< 陣列1 的索引
    int rgt_idx = 0; ///< 陣列2 的索引
    int k = lft;     ///< 合併後陣列的索引

    while (lft_idx < arr_lft_size && rgt_idx < arr_rgt_size) {
        if (arr_lft[lft_idx] <= arr_rgt[rgt_idx]) {
            arr[k] = arr_lft[lft_idx];
            lft_idx++;
        } else {
            arr[k] = arr_rgt[rgt_idx];
            rgt_idx++;
        }
        k++;
    }

    while (lft_idx < arr_lft_size) {
        arr[k] = arr_lft[lft_idx];
        lft_idx++;
        k++;
    }
    while (rgt_idx < arr_rgt_size) {
        arr[k] = arr_rgt[rgt_idx];
        rgt_idx++;
        k++;
    }
}

void merge_sort(int arr[], int lft, int rgt) {
    if (lft >= rgt) {
        return; // 最基底的狀態，陣列僅有一個元素或為空
    }
    int mid = lft + (rgt - lft) / 2;
    merge_sort(arr, lft, mid);     // 先排左半邊
    merge_sort(arr, mid + 1, rgt); // 再排右半邊
    merge(arr, lft, mid, rgt);     // 合併排好的左右兩邊
}

// 沒什麼特別的意義
// 只是我不想修改 main 裡面呼叫 sort 的方式
// 所以把 sort 當成一個輔助函數呼叫 merge sort
// 僅此而已
void sort(int arr[], int arr_size) {
    merge_sort(arr, 0, arr_size - 1);
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
// ZeroJudge AC(9ms, 316KB)
