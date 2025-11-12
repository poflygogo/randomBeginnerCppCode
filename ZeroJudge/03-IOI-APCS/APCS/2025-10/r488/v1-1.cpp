#include <climits>
#include <iostream>
#include <vector>

int main() {
    int rows, cols, deep;
    std::cin >> rows >> cols >> deep;
    std::vector<std::vector<int>> graph(rows, std::vector<int>(cols, deep));
    std::vector<std::vector<int>> dinosaur(rows, std::vector<int>(cols, 0));

    int total_dinosaur;
    std::cin >> total_dinosaur;
    for (int i = 0; i < total_dinosaur; i++) {
        int a, b;
        std::cin >> a >> b;
        dinosaur[a][b]++;
    }

    int m;
    std::cin >> m;
    while (m--) {
        int a, b, s, d;
        std::cin >> a >> b >> s >> d;

        bool flag = false;
        int top = std::max(0, a - s / 2);
        int dwn = std::min(rows - 1, a + s / 2);
        int lft = std::max(0, b - s / 2);
        int rgt = std::min(cols - 1, b + s / 2);
        for (int i = top; i <= dwn; i++) {
            for (int j = lft; j <= rgt; j++) {
                if (dinosaur[i][j] > 0) {
                    total_dinosaur -= dinosaur[i][j];
                    dinosaur[i][j] = 0;
                    flag = true;
                }
            }
        }

        if (flag) {
            continue;
        }
        for (int i = top; i <= dwn; i++) {
            for (int j = lft; j <= rgt; j++) {
                graph[i][j] -= d;
            }
        }
    }

    int max_deep = INT_MIN;
    int min_deep = deep;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (graph[i][j] > max_deep) {
                max_deep = graph[i][j];
            }
            if (graph[i][j] < min_deep) {
                min_deep = graph[i][j];
            }
        }
    }

    std::cout << max_deep << ' ' << min_deep << ' ' << total_dinosaur;
}
