// ZeroJudge c463
// APCS 2017-10 3 樹狀圖分析 (Tree Analyses)
// c++14

#include <algorithm>  // max_element
#include <iostream>
#include <iterator>  // distance
#include <numeric>   // iota, accumlate
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> parents(n + 1);
    std::iota(parents.begin(), parents.end(), 0);
    std::vector<int> leaves;  // record leaf nodes
    for (int i = 1; i <= n; ++i) {
        int k;
        std::cin >> k;
        if (k == 0) {
            leaves.push_back(i);
            continue;
        }
        while (k--) {
            int v;
            std::cin >> v;
            parents[v] = i;
        }
    }

    // dfs
    // from leaves to root
    std::vector<int> height(n + 1, 0);
    for (int node : leaves) {
        node = parents[node];
        int cnt = 0;
        while (true) {
            cnt++;
            if (height[node] >= cnt) {
                break;
            }
            height[node] = cnt;
            if (parents[node] == node) {
                break;
            }
            node = parents[node];
        }
    }

    std::cout << std::distance(height.begin(), std::max_element(height.begin(), height.end()))
              << '\n'
              << std::accumulate(height.begin(), height.end(), 0);
}
