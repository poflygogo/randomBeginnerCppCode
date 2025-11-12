#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main() {
    std::map<std::string, int> counter;
    int n, m;
    std::string s;
    std::cin >> n >> m;
    while (n--) {
        std::cin >> s;
        counter[s]++;
    }
    std::vector<std::pair<int, std::string>> arr;
    arr.reserve(counter.size());
    for (const std::pair<std::string, int>& item : counter) {
        arr.push_back({item.second, item.first});
    }
    std::sort(arr.begin(), arr.end(), std::greater<std::pair<int, std::string>>());
    for (int i = 0; i < m; i++) {
        std::cout << arr[i].second << ' ';
    }
}
