#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr;
    arr.reserve(10000);
    int n;
    while (cin >> n) {
        auto it = lower_bound(arr.begin(), arr.end(), n);
        arr.insert(it, n);
        int i = arr.size() / 2;
        if (arr.size() % 2 == 0) {
            cout << (arr[i - 1] + arr[i]) / 2 << '\n';
        } else {
            cout << arr[i] << '\n';
        }
    }
}
