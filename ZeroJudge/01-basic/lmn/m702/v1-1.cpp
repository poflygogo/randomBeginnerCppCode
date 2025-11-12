#include <iostream>
#include <map>
#include <queue>

int main() {
    std::map<std::string, int> counter;
    int n, m;
    std::string s;
    std::cin >> n >> m;
    while (n--) {
        std::cin >> s;
        counter[s]++;
    }
    std::priority_queue<std::pair<int, std::string>> maxHeap;
    for (const std::pair<std::string, int>& i : counter) {
        maxHeap.push({i.second, i.first});
    }
    while (m--) {
        std::cout << maxHeap.top().second << ' ';
        maxHeap.pop();
    }
}
