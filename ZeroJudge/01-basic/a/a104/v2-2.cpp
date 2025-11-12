// 使用 algorithm 的 sort 進行排序

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr_size;
    while (cin >> arr_size) {
        vector<int> arr;
        int tmp;
        for (int i = 0; i < arr_size; i++) {
            cin >> tmp;
            arr.push_back(tmp);
        }
        sort(arr.begin(), arr.end());
        for (int ele : arr) {
            cout << ele << " ";
        }
        cout << endl;
    }
}
