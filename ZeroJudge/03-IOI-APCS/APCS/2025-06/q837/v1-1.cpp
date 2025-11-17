#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

int main() {
    int m, n, k;
    std::cin >> m >> n >> k;
    std::vector<std::string> texts(m);
    for (size_t i = 0; i < m; i++) {
        std::cin >> texts[i];
    }
    int score = 0;
    while (k--) {
        for (size_t i = 0; i < m; i++) {
            int r;
            std::cin >> r;
            r = (r >= 0 ? r % n : r % n + n);
            r = n - r;
            std::string& t = texts[i];
            t = t.substr(r) + t.substr(0, r);
        }

        for (size_t col = 0; col < n; col++) {
            std::map<char, int> counter;
            for (size_t row = 0; row < m; row++) {
                counter[texts[row][col]]++;
            }
            int max_val = 0;
            for (auto&& i : counter) {
                if (i.second > max_val) {
                    max_val = i.second;
                }
            }
            score += max_val;
        }
    }

    std::cout << score;
}
