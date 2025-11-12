#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct Skill {
    std::vector<int> pre;
    std::vector<int> next;
    bool unlock = false;
};

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> skill_bools(k);
    for (int i = 0; i < k; i++) {
        std::cin >> skill_bools[i];
    }

    std::vector<Skill> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        graph[u].next.push_back(v);
        graph[v].pre.push_back(u);
    }

    int cnt = k;
    std::queue<int> q;
    for (int i = 0; i < skill_bools.size(); i++) {
        graph[skill_bools[i]].unlock = true;
        q.push(skill_bools[i]);
    }

    while (!q.empty()) {
        int skill_id = q.front();
        q.pop();

        if (!graph[skill_id].unlock) {
            if (std::all_of(graph[skill_id].pre.begin(), graph[skill_id].pre.end(),
                            [&graph](const int s) { return graph[s].unlock; })) {
                graph[skill_id].unlock = true;
                cnt++;
            } else {
                continue;
            }
        }

        for (int i : graph[skill_id].next) {
            if (graph[i].unlock) {
                continue;
            }

            if (std::all_of(graph[i].pre.begin(), graph[i].pre.end(),
                            [&graph](int j) { return graph[j].unlock; })) {
                graph[i].unlock = true;
                cnt++;
            }

            q.push(i);
        }
    }

    std::cout << cnt;
}
