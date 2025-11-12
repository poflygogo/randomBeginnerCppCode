#include <array>
#include <iostream>
#include <numeric>
#include <unordered_map>

constexpr std::array<int, 10> cac = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
std::unordered_map<std::string, int> pre_cac;

void initialize() {
    std::array<int, 10> tokens;
    std::iota(tokens.begin(), tokens.end(), 0);
    // ㄘ我的氣功波啦
    for (auto&& a : tokens) {
        for (auto&& b : tokens) {
            for (auto&& c : tokens) {
                for (auto&& d : tokens) {
                    std::string s = std::to_string(a) + std::to_string(b) + std::to_string(c) +
                                    std::to_string(d);
                    pre_cac[s] = cac[a] + cac[c] + b + d;
                }
            }
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    initialize();

    int n;
    std::string a, b, c, d;
    std::cin >> n;
    while (n--) {
        std::cin >> a >> b >> c >> d;
        int res = pre_cac[a] + pre_cac[b] + pre_cac[c] + pre_cac[d];
        std::cout << (res % 10 ? "Invalid" : "Valid") << '\n';
    }
}
