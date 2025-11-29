// ZeroJudge b966
// APCS 2016-03 3. 線段覆蓋長度
// C++14

#include <algorithm>  // sort
#include <iostream>
#include <utility>  // pair
#include <vector>

int main() {
    int length;
    std::cin >> length;
    std::vector<std::pair<int, int>> arr(length);
    for (int i = 0; i < length; ++i) {
        std::cin >> arr[i].first >> arr[i].second;
    }
    std::sort(arr.begin(), arr.end());
    int cnt = 0;
    int start = arr.front().first;
    int end = arr.front().second;
    for (size_t i = 1; i < length; ++i) {
        std::pair<int, int> &p = arr[i];
        if (p.first <= end) {
            if (p.second <= end) {
                continue;
            } else {
                end = p.second;
            }
        } else {
            cnt += end - start;
            start = p.first;
            end = p.second;
        }
    }
    cnt += end - start;
    std::cout << cnt;
}
