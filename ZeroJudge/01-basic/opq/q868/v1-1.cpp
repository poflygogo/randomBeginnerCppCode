#include <iostream>
#include <map>
#include <queue>
#include <set>

bool IsConnected(const std::map<int, std::set<int>>& graph, const int a, const int b) {
    if (a == b) {
        return true;
    }
    std::set<int> visited;
    std::queue<int> q;
    q.push(a);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (graph.find(curr) == graph.end()) {
            continue;
        }

        for (auto&& i : graph.at(curr)) {
            if (i == b) {
                return true;
            } else if (!visited.count(i)) {
                q.push(i);
                visited.insert(i);
            }
        }
    }
    return false;
}

int main() {
    std::map<int, std::set<int>> graph;
    int n;
    int a, b;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a >> b;
        graph[a].insert(b);
    }
    std::cin >> a >> b;
    std::cout << (IsConnected(graph, a, b) ? "Yay" : "Come on");
}
