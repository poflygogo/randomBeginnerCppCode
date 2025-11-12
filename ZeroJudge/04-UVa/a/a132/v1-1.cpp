#include <algorithm>
#include <iostream>

std::pair<std::string, int> to_bit(int n) {
    std::string res;
    int cnt = 0;
    while (n > 0) {
        res += (n % 2) ? '1' : '0';
        cnt += (n % 2);
        n /= 2;
    }
    std::reverse(res.begin(), res.end());
    return {res, cnt};
}

int main() {
    int n;
    while (std::cin >> n && n) {
        std::pair<std::string, int> res = to_bit(n);
        std::cout << "The parity of " << res.first << " is " << res.second << " (mod 2).\n";
    }
}
