#include <algorithm>  // std::reverse
#include <cmath>      // pow
#include <iostream>
#include <sstream>  // std::istringstream
#include <string>
#include <vector>

void FactorizeHelper(std::vector<std::pair<int, int>>& arr, int& n, const int p) {
    int cnt = 0;
    while (n % p == 0) {
        cnt++;
        n /= p;
    }
    if (cnt > 0) {
        arr.push_back({p, cnt});
    }
}

std::vector<std::pair<int, int>> Factorize(int n) {
    std::vector<std::pair<int, int>> res;
    FactorizeHelper(res, n, 2);
    FactorizeHelper(res, n, 3);
    for (int i = 5; i * i <= n; i += (i % 6 == 1 ? 4 : 2)) {
        FactorizeHelper(res, n, i);
    }
    if (n > 1) {
        res.push_back({n, 1});
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    std::string s;
    std::istringstream iss;
    while (std::getline(std::cin, s) && s != "0") {
        iss.clear();
        iss.str(s);

        int num = 1;
        int base, exp;
        while (iss >> base >> exp) {
            num *= pow(base, exp);
        }

        num--;
        std::vector<std::pair<int, int>> res = Factorize(num);
        for (int i = 0; i < res.size(); i++) {
            std::cout << res[i].first << ' ' << res[i].second << (i + 1 < res.size() ? ' ' : '\n');
        }
    }
}
