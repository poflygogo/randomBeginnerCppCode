#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    short size;
    cin >> size;
    vector<pair<int, int>> arr(size);
    for (int i = 0; i < size; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    for (const pair<int, int> &item : arr) {
        cout << item.first << " " << item.second << '\n';
    }
}
