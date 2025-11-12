#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, tmp;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    vector<int> result;
    int curr_max_cnt = 0;
    int i = 0, j = 1;
    while (i < n) {
        while (j < n && arr[i] == arr[j]) {
            j++;
        }
        int curr_cnt = j - i;
        if (curr_cnt > curr_max_cnt) {
            result.clear();
            result.push_back(arr[i]);
            curr_max_cnt = curr_cnt;
        } else if (curr_cnt == curr_max_cnt) {
            result.push_back(arr[i]);
        }
        i = j++;
    }

    sort(result.begin(), result.end());
    for (const int &item : result) {
        cout << item << ' ' << curr_max_cnt << '\n';
    }
}
