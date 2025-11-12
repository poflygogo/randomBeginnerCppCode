#include <array>
#include <iostream>

int main() {
    constexpr int sites_cnt = 10;
    std::array<std::string, 10> sites;
    int t;
    std::cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        std::string s;
        int val;
        int max_val = 0;
        int cnt = 0;
        for (int i = 0; i < sites_cnt; i++) {
            std::cin >> s >> val;
            if (val < max_val) {
                continue;
            }
            if (val > max_val) {
                max_val = val;
                cnt = 0;
            }
            sites[cnt] = s;
            cnt++;
        }
        std::cout << "Case #" << test_case << ":\n";
        for (int i = 0; i < cnt; i++) {
            std::cout << sites[i] << '\n';
        }
    }
}
