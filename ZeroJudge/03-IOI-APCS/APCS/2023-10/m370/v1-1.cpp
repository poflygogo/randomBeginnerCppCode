#include <algorithm>  // lower_bound, sort
#include <cstddef>    // distance
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    vector<int> foods(n);
    for (int i = 0; i < n; i++) {
        cin >> foods[i];
    }
    // 排序的目的是為了懶人判斷是大於 x 的元素較多，還是小於 x 的元素較多
    sort(foods.begin(), foods.end());

    // binary search
    auto it = lower_bound(foods.begin(), foods.end(), x);
    size_t idx = distance(foods.begin(), it);

    if (idx > n / 2) {
        cout << idx << ' ' << foods.front();
    } else {
        cout << n - idx << ' ' << foods.back();
    }
}
