#include <array>
#include <iostream>
#include <set>

void solve(const int max_row, const int max_col, int row, int col, const std::string& d_str, const std::string& commands) {
    static const std::string directions = "NESW";
    static const std::array<std::pair<int, int>, 4> offsets = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    static std::set<std::pair<int, int>> visited;
    int dir = directions.find(d_str);
    for (char c : commands) {
        switch (c) {
            case 'R':
                dir++;
                break;
            case 'L':
                dir--;
                break;
            case 'F':
                dir = (dir + 4) % 4;
                row += offsets[dir].first;
                col += offsets[dir].second;

                if (0 <= row && row <= max_row && 0 <= col && col <= max_col) {
                    continue;
                }
                // 移動後如果會超出範圍就倒退
                row -= offsets[dir].first;
                col -= offsets[dir].second;

                if (visited.find({row, col}) == visited.end()) {
                    dir = (dir + 4) % 4;
                    std::cout << row << ' ' << col << ' ' << directions[dir] << ' ' << "LOST\n";
                    visited.insert({row, col});
                    return;
                }
                break;
            default:
                // should not happen
                std::cout << "what is \"" << c << "\"?\n";
                return;
        }
    }
    dir = (dir + 4) % 4;
    std::cout << row << ' ' << col << ' ' << directions[dir] << '\n';
}

int main() {
    int max_row, max_col;
    std::cin >> max_row >> max_col;
    int row, col;
    std::string d_str, commands;
    while (std::cin >> row >> col >> d_str >> commands) {
        solve(max_row, max_col, row, col, d_str, commands);
    }
}
