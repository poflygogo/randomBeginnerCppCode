// UVa 989 - Su Doku
// ZeroJudge 263
// C++14

#include <cstddef>  // size_t
#include <iostream>
#include <vector>

class SudokuSolver {
private:
    using Sudoku = std::vector<std::vector<int>>;

    Sudoku graph;
    int box_size, graph_size;

    // 檢查傳入的原始數獨題目是否合理
    bool isValidInit() {
        // 我嫌名字長，縮短一下
        using Cache = std::vector<std::vector<char>>;

        // row_info[i][num]: 第 i 列是否出現 num
        // col_info[i][num]: 第 i 欄是否出現 num
        // box_info[i][num]: 第 i 小方格是否出現 num
        Cache row_info(graph_size, std::vector<char>(graph_size + 1, false));
        Cache col_info(graph_size, std::vector<char>(graph_size + 1, false));
        Cache box_info(graph_size, std::vector<char>(graph_size + 1, false));

        for (size_t r = 0; r < graph_size; ++r) {
            for (size_t c = 0; c < graph_size; ++c) {
                int val = graph[r][c];

                // 空格，直接跳過
                if (val == 0) { continue; }

                // 無效數值
                if (val < 1 || val > graph_size) { return false; }

                // 查找是否有重複
                int box_id = (r / box_size) * box_size + (c / box_size);
                if (row_info[r][val] || col_info[c][val] || box_info[box_id][val]) { return false; }

                row_info[r][val] = col_info[c][val] = box_info[box_id][val] = true;
            }
        }

        return true;  // 一切順利
    }

    // 檢查目標位置是否可以填入 val
    bool isValid(const int row, const int col, const int val) {
        for (size_t x = 0; x < graph_size; ++x) {
            // 橫向檢查
            if (graph[row][x] == val) { return false; }

            // 縱向檢查
            if (graph[x][col] == val) { return false; }

            // 檢查小方格
            size_t box_r = box_size * (row / box_size) + (x / box_size);
            size_t box_c = box_size * (col / box_size) + (x % box_size);
            if (graph[box_r][box_c] == val) { return false; }
        }
        return true;
    }

    // dfs
    // 返回 bool 值，用來標記是否有解
    bool _solve() {
        for (size_t r = 0; r < graph_size; ++r) {
            for (size_t c = 0; c < graph_size; ++c) {
                if (graph[r][c] != 0) { continue; }

                for (int val = 1; val <= graph_size; ++val) {
                    if (!isValid(r, c, val)) { continue; }

                    graph[r][c] = val;
                    if (_solve()) { return true; }  // 遞迴
                    graph[r][c] = 0;
                }

                return false;  // 所有數字都不匹配
            }
        }

        return true;  // 一切順利
    }

public:
    // 構造函數，順便讀取資料
    SudokuSolver(int size) : box_size(size), graph_size(size * size) {
        graph.resize(graph_size);
        for (std::vector<int> &row : graph) {
            row.resize(graph_size);
            for (int &cell : row) { std::cin >> cell; }
        }
    };

    bool solve() {
        // 1. 檢查輸入是否合理
        if (!isValidInit()) { return false; }

        // 2. 嘗試找答案
        return _solve();
    }

    // 懶人輸出
    void print_sudoku() {
        for (const std::vector<int> &row : graph) {
            for (size_t i = 0; i < row.size(); ++i) {
                std::cout << row[i] << (i + 1 < row.size() ? ' ' : '\n');
            }
        }
    }
};

int main() {
    int n;
    bool is_first = true;
    while (std::cin >> n) {
        SudokuSolver s(n);

        if (!is_first) { std::cout << '\n'; }
        is_first = false;

        if (s.solve()) {
            s.print_sudoku();
        } else {
            std::cout << "NO SOLUTION" << '\n';
        }
    }
}
