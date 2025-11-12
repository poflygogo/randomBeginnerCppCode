#include <algorithm>
#include <iostream>
using namespace std;

bool custom_compare(int a, int b) {
    if (a % 10 == b % 10) {
        return a > b;
    } else {
        return a % 10 < b % 10;
    }
}

int main() {
    int n;
    while (cin >> n) {
        int arr[n];
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            arr[i] = tmp;
        }
        sort(arr, arr + n, custom_compare);
        for (int item : arr) {
            cout << item << " ";
        }
        cout << endl;
    }
}