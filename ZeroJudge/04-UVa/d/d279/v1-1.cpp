// UVa 280 - Vertex
// ZeroJudge d279
// C++14

#include <iostream>
#include <vector>

// 使用鄰接矩陣表示有向圖
using AdjacencyMatrix = std::vector<std::vector<char>>;

// DFS 遍歷函數，標記所有從 start 可到達的頂點
void pathThrough(const AdjacencyMatrix &links, std::vector<char> &visited, int start) {
    const std::vector<char> &arr = links.at(start);
    for (int i = 0; i < arr.size(); ++i) {
        if (arr.at(i) && !visited.at(i)) {
            visited.at(i) = true;
            pathThrough(links, visited, i);
        }
    }
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        // 建立鄰接矩陣, n + 1 是配合測資的節點編號從 1 開始計算
        AdjacencyMatrix links(n + 1, std::vector<char>(n + 1, false));

        int start;
        while (std::cin >> start && start != 0) {
            int target;
            while (std::cin >> target && target != 0) {
                links.at(start).at(target) = true;
            }
        }

        int to_check;
        std::cin >> to_check;
        while (to_check--) {
            int k;
            std::cin >> k;
            // 標記從 k 出發可到達的頂點
            std::vector<char> visited(n + 1, false);
            pathThrough(links, visited, k);

            // 找出所有不可到達的頂點
            std::vector<int> result;
            for (int i = 1; i < visited.size(); ++i) {
                if (!visited.at(i)) { result.push_back(i); }
            }

            // 輸出結果
            std::cout << result.size();
            for (const int val : result) {
                std::cout << ' ' << val;
            }
            std::cout << '\n';
        }
    }
}
