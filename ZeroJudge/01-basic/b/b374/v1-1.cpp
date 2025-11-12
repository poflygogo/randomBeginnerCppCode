#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 使用 map 統計每個元素的數量

int main() {
    int n, tmp;
    cin >> n;

    unordered_map<int, int> counter;
    counter.reserve(n);
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        counter[tmp] += 1;
    }

    int max_val = 0;
    for (const pair<int, int> item : counter) {
        max_val = max(max_val, item.second);
    }

    vector<int> result;
    for (const pair<int, int> item : counter) {
        if (item.second == max_val) {
            result.push_back(item.first);
        }
    }

    sort(result.begin(), result.end());
    for (const int &item : result) {
        cout << item << ' ' << max_val << '\n';
    }
}
