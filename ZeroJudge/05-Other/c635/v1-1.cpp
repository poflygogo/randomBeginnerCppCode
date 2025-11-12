#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<int> arr, arr_odd, arr_even;

    // ---------------------------------------------------
    // 逐行讀資料並放到陣列中
    string line, token;
    stringstream stream;
    while (getline(cin, line)) {
        stream.clear();
        stream.str(line);
        while (getline(stream, token, ',')) {
            arr.push_back(stoi(token));
        }
    // ----------------------------------------------------
    // 把陣列中的元素根據位置分類，排序，再放回原陣列

        for (int i = 0; i < arr.size(); i += 2) {
            arr_even.push_back(arr[i]);
        }
        for (int i = 1; i < arr.size(); i += 2) {
            arr_odd.push_back(arr[i]);
        }

        sort(arr_even.begin(), arr_even.end());
        sort(arr_odd.begin(), arr_odd.end());
        arr.clear();

        for (int i = 0, j = 0; i < arr_even.size() || j < arr_odd.size();i++, j++) {
            arr.push_back(arr_even[i]);
            if (j < arr_odd.size())
                arr.push_back(arr_odd[j]);
        }

        for (int i = 0; i < arr.size() - 1; i++) {
            cout << arr[i] << ',';
        }
        cout << arr.back() << '\n';

        arr.clear();
        arr_even.clear();
        arr_odd.clear();
    }
}