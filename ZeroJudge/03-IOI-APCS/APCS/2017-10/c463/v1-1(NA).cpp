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
    for (int parent = 1; parent <= n; ++parent) {
        int k;
        std::cin >> k;
        if (k == 0) {
            leaves.push_back(parent);
            continue;
        }
        while (k--) {
            int child;
            std::cin >> child;
            parents[child] = parent;
        }
    }

    // dfs
    // from leaves to root
    std::vector<int> heights(n + 1, 0);
    for (int node : leaves) {
        node = parents[node];
        int cnt = 0;
        while (true) {
            cnt++;
            if (heights[node] >= cnt) {
                break;
            }
            heights[node] = cnt;
            if (parents[node] == node) {
                break;
            }
            node = parents[node];
        }
    }

    std::cout << std::distance(heights.begin(), std::max_element(heights.begin(), heights.end()))
              << '\n'
              << std::accumulate(heights.begin(), heights.end(), 0);
}
