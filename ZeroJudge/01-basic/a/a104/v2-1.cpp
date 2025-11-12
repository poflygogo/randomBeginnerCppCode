// 使用 algorithm 的 sort 進行排序

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int arr_size;
    while (cin >> arr_size) {
        int arr[arr_size];
        for (int i = 0; i < arr_size; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + arr_size);
        for (int ele : arr) {
            cout << ele << " ";
        }
        cout << endl;
    }
}
