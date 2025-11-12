#include <algorithm>
#include <iostream>
#include <vector>

std::string FibBase(int n) {
    // 不確定陣列該開多大，所以按需擴充
    static std::vector<int> fib = {1, 2};

    // 紀錄總和為 n 的費波納契數
    std::vector<int> tmp;
    while (n) {
        int idx = 0;
        while (fib[idx] <= n) {
            idx++;
            // 數字不夠用就往後補新的
            if (idx == fib.size()) {
                fib.push_back(*(fib.end() - 1) + *(fib.end() - 2));
            }
        }
        tmp.push_back(fib[idx - 1]);
        n -= fib[idx - 1];
    }

    std::string res = "1";
    for (int i = 1; i < tmp.size(); i++) {
        int k = std::distance(std::lower_bound(fib.begin(), fib.end(), tmp[i]),
                              std::lower_bound(fib.begin(), fib.end(), tmp[i - 1]));
        res.append(std::string(k - 1, '0'));
        res += '1';
    }
    if (tmp.back() != 1) {
        int k = std::distance(fib.begin(), std::lower_bound(fib.begin(), fib.end(), tmp.back()));
        res.append(std::string(k, '0'));
    }
    return res;
}

int main() {
    int t, n;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        std::cout << n << " = " << FibBase(n) << " (fib)\n";
    }
}
